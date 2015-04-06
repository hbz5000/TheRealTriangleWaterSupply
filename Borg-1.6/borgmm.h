/* Copyright 2012-2013 The Pennsylvania State University
 *
 * This software was written by David Hadka and others.
 * 
 * The use, modification and distribution of this software is governed by the
 * The Pennsylvania State University Research and Educational Use License.
 * You should have received a copy of this license along with this program.
 * If not, contact <dmh309@psu.edu>.
 */
#ifndef _BORG_MMDRIVER_H_
#define _BORG_MMDRIVER_H_

#ifdef _BORG_MSDRIVER_H_
#error do not include borgms.h if you are including borgmm.h
#endif

#ifdef _BORG_H_
#error do not include borg.h if you are including borgmm.h
#endif

#include "borg.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Enumeration of initialization strategies.
 */
typedef enum BORG_Initialization {
	INITIALIZATION_UNIFORM,
	INITIALIZATION_LATIN,
	INITIALIZATION_LATIN_GLOBAL
} BORG_Initialization;

/**
 * Returns the difference between two high-resolution time values.  The
 * differences is reported in microseconds.
 */
long BORG_Timer_diff(struct timeval* start, struct timeval* end);

/**
 * Sets the referenced timeval structure to the current high-resolution
 * time.
 */
void BORG_Timer_now(struct timeval* time);

/**
 * Output timing data to files with the specified prefix.  The filename
 * should contain two %%d to be replaced by the island and island rank.
 */
void BORG_Algorithm_output_timing(char* filename);

/**
 * Output runtime dynamics to the specified file.  The filename should
 * contain one %%d to be replaced by the island index.
 */
void BORG_Algorithm_output_runtime(char* filename);

/**
 * Output runtime dynamics with the specified frequency.
 */
void BORG_Algorithm_output_frequency(int frequency);

/**
 * Output runtime dynamics in the format of Aerovis.
 */
void BORG_Algorithm_output_aerovis();

/**
 * Returns the next solution to be evaluated.
 */
BORG_Solution BORG_Master_next(BORG_Algorithm algorithm);

/**
 * Sends a shutdown signal to the specified worker node.
 */
void BORG_Master_shutdown(int rank);

/**
 * Sends a solution for evaluation to the specified worker node.
 */
void BORG_Master_send(int rank, BORG_Solution solution);

/**
 * Receives an evaluated solution from any worker node, returning the rank of
 * the worker node which provided the solution.
 */
int BORG_Master_receive();

/**
 * Injects the specified number of individuals, adding them onto the solution
 * queue to be evaluated and added into the population.
 */
void BORG_Master_injection(BORG_Algorithm algorithm, int size);

/**
 * Performs a restart on the MS Borg algorithm; the only difference is any new,
 * randomly-generated solutions are added to the queue.
 */
void BORG_Master_restart(BORG_Algorithm algorithm);

/**
 * Initializes the MS Borg algorithm, sending the initial population for evaluation.
 */
void BORG_Master_initialize(BORG_Algorithm algorithm);

/**
 * Runs the initialized MS Borg algorithm until all allocated NFE are consumed.
 */
void BORG_Master_loop(BORG_Algorithm algorithm);

/**
 * Main thread for the master node, returning the end-of-run approximation set.
 */
BORG_Archive BORG_Master_run();

/**
 * Serializes a solution into an array.  Objectives, constraints and the operator
 * flag are included when the full flag is set.
 */
void BORG_Solution_serialize(BORG_Solution solution, double* output, int full);

/**
 * Deserializes a solution from an array.
 */
BORG_Solution BORG_Solution_deserialize(double* input, int full);

/**
 * Main thread for the controller node, maintaining a global archive and
 * sending help to masters when needed.  Returns the global archive.
 */
BORG_Archive BORG_Controller_run();

/**
 * Main thread for the worker node, evaluating solutions until a shutdown
 * signal is received.
 */
void BORG_Worker_run();

/**
 * Starts the MS/MM Borg algorithm, assigning each node a role (master, worker, controller).  
 */
void BORG_Algorithm_ms_startup(int* argc, char*** argv);

/**
 * Allocates the specified number of objective function evaluations when running the MS/MM Borg
 * algorithm.  The algorithm will terminate automatically if the NFE exceeds this threshold.
 */
void BORG_Algorithm_ms_max_evaluations(int maxEvaluations);

/**
 * Allocates the specified number of hours when running the MS/MM Borg algorithm.  The algorithm
 * will terminate automatically if the wallclock time exceeds this threshold.
 */
void BORG_Algorithm_ms_max_time(double maxHours);

/**
 * Specifies the number of islands.  Each island operates as an independent master-slave
 * execution.  Remaining nodes which are not the masters become slaves, and are assigned
 * to a single master node.  When set to a number > 1, this enables multi-master Borg.
 */
void BORG_Algorithm_ms_islands(int numberOfIslands);

/**
 * Specifies the frequency at which master nodes update the global archive.
 */
void BORG_Algorithm_ms_update_frequency(int updateFrequency);

/**
 * Sets the initialization strategy.
 */
void BORG_Algorithm_ms_initialization(BORG_Initialization initialization);

/**
 * The number of continuous restarts at the maximum mutation rate prior to initiating a
 * request for help.
 */
void BORG_Algorithm_ms_delay_for_help(int delayForHelp);

/**
 * Runs the MS/MM Borg algorithm on the specified problem given the allocated
 * resources.  This method must be invoked on all nodes, but only the master node will
 * return the result; all other nodes return with NULL.  For MM Borg, only the
 * controller node will return the results; all other nodes return NULL.
 */
BORG_Archive BORG_Algorithm_ms_run(BORG_Problem problem);

/**
 * Shuts down the MS/MM Borg algorithm.  No additional methods should be invoked.
 */
void BORG_Algorithm_ms_shutdown();

#ifdef __cplusplus
}
#endif

#endif
