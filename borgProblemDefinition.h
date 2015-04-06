#ifndef borgProblemDefinition_h
#define borgProblemDefinition_h

#include "Borg-1.6/borgms.h"

void setProblemDefinition(BORG_Problem &problem, int formulation)
{
	// The parameter bounds are the same for all formulations

	BORG_Problem_set_bounds(problem, 0, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 1, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 2, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 3, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 4, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 5, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 6, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 7, 0.1, 0.47);
	BORG_Problem_set_bounds(problem, 8, 0.0, 0.37);
	BORG_Problem_set_bounds(problem, 9, 0.05, 0.42);
	BORG_Problem_set_bounds(problem, 10, 0.355, 0.725);
	BORG_Problem_set_bounds(problem, 11, 0.0, 0.1);
	BORG_Problem_set_bounds(problem, 12, 0.0, 0.1);
	BORG_Problem_set_bounds(problem, 13, 0.0, 0.1);
	BORG_Problem_set_bounds(problem, 14, 0.0, 0.1);
	BORG_Problem_set_bounds(problem, 15, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 16, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 17, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 18, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 19, 0.0, 0.02);
	BORG_Problem_set_bounds(problem, 20, 0.0, 0.02);
	BORG_Problem_set_bounds(problem, 21, 0.0, 0.02);
	BORG_Problem_set_bounds(problem, 22, 0.0, 0.02);
	BORG_Problem_set_bounds(problem, 23, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 24, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 25, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 26, 0.001, 1.0);
	BORG_Problem_set_bounds(problem, 27, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 28, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 29, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 30, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 31, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 32, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 33, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 34, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 35, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 36, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 37, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 38, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 39, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 40, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 41, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 42, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 43, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 44, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 45, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 46, 0.0, 100.0);
	BORG_Problem_set_bounds(problem, 47, 0.0, 100.0);
	BORG_Problem_set_bounds(problem, 48, 0.0, 100.0);
	BORG_Problem_set_bounds(problem, 49, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 50, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 51, 0.0, 1.0);
	BORG_Problem_set_bounds(problem, 52, 0.0, 10000.0);
	BORG_Problem_set_bounds(problem, 53, 0.0, 20.0);
	BORG_Problem_set_bounds(problem, 54, 0.0, 20.0);
	BORG_Problem_set_bounds(problem, 55, 0.0, 20.0);

	
	// Set epsilons for objectives
	// Original values: (works fine for Formulations 0-4)
	
	BORG_Problem_set_epsilon(problem, 0, 0.001);
	BORG_Problem_set_epsilon(problem, 1, 5.0);
	BORG_Problem_set_epsilon(problem, 2, 0.01);
	BORG_Problem_set_epsilon(problem, 3, 0.005);
	BORG_Problem_set_epsilon(problem, 4, 0.001);
	BORG_Problem_set_epsilon(problem, 5, 0.005);
	BORG_Problem_set_epsilon(problem, 6, 0.005);
	BORG_Problem_set_epsilon(problem, 7, 0.01);

	if(formulation >= 2)
		BORG_Problem_set_epsilon(problem, 5, 0.01);


}

#endif
