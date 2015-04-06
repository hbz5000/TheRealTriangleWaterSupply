#!/bin/bash
#$ -V                      # Inherit the submission environment
#$ -cwd                    # Start job in submission directory
#$ -N Test_S1_256P                # Job Name
#$ -e ./error/$JOB_NAME.err                    # Combine stderr and stdout
#$ -o ./output/$JOB_NAME.out   # Name of the output file (eg. myMPI.oJobID)
#$ -pe 16way 256            # Requests 16 tasks/node, 32 cores total
#$ -q development             # Queue name "normal"
#$ -l h_rt=01:00:00        # Run time (hh:mm:ss) - 1.5 hours
#$ -M jdh33@psu.edu              # address for email notification
#$ -m be                   # email at Begin and End of job
time ibrun ./triangleSimulation -m batch -r 1000 -s 1 -c 5 -b 0              # Run the MPI executable named "a.out"