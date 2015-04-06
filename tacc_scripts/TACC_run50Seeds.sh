#!/bin/bash
#$ -V                      # Inherit the submission environment
#$ -cwd                    # Start job in submission directory
#$ -e ./error/$JOB_NAME.err                    # Combine stderr and stdout
#$ -o ./output/$JOB_NAME.out   # Name of the output file (eg. myMPI.oJobID)
#$ -pe 16way 1024            # Requests 16 tasks/node, 32 cores total
#$ -q long           # Queue name "normal"
#$ -l h_rt=48:00:00        # Run time (hh:mm:ss) - 1.5 hours
#$ -M jdh33@psu.edu              # address for email notification
#$ -m be                   # email at Begin and End of job

# For TACC:
module unload mvapich
module swap pgi intel
module load mvapich

# 50 random seeds
NSEEDS=50
SEEDS=$(seq 1 ${NSEEDS})

for SEED in ${SEEDS}
do
	ibrun ./triangleSimulation -m batch -r 1000 -s ${SEED} -c ${FORMULATION} -b ${OBJ_TYPE}
done