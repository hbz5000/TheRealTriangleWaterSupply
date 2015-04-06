#!/bin/bash
#$ -V                      # Inherit the submission environment
#$ -cwd                    # Start job in submission directory
#$ -e ./error/$JOB_NAME.err                    # Combine stderr and stdout
#$ -o ./output/$JOB_NAME.out   	# Name of the output file (eg. myMPI.oJobID)
#$ -pe 1way 16            		# Trick for serial jobs
#$ -q serial              		# Queue name "serial"
#$ -l h_rt=12:00:00        		# Run time (hh:mm:ss) - 1.5 hours
#$ -M jdh33@psu.edu             # address for email notification
#$ -m be                   		# email at Begin and End of job

FORMULATIONS=("0" "1" "2" "3" "4" "5" "6")
NSEEDS=50
SEEDS=$(seq 1 ${NSEEDS})
OBJCOUNT=("3" "3" "4" "5" "5" "5" "6")

CUTSTART=32 # The column of the first objective value
CUTEND=("34" "34" "35" "36" "36" "36" "37")
EPSILONS=("0.001,0.01,0.0005" "0.001,0.01,0.0005" "0.001,0.01,0.0005,0.001" "0.001,0.01,0.0005,0.001,0.001" "0.001,0.01,0.0005,0.001,0.001" "0.001,0.01,0.0005,0.001,0.001" "0.001,0.01,0.0005,0.001,0.001,0.005")

JAVA_ARGS="-Xmx128m -classpath MOEAFramework-1.16-Executable.jar"

# Some file processing ... (FINDEX and OBJ_TYPE are passed in)
for SEED in ${SEEDS}
do
	DIRECTORY="./output/O${OBJ_TYPE}_F${FORMULATIONS[$FINDEX]}"
	FILENAME="CBorg_NCTriangle_O${OBJ_TYPE}_F${FORMULATIONS[$FINDEX]}_S${SEED}"
	RUNTIME_FILE="${DIRECTORY}/${FILENAME}.runtime"
	OP_PROB_FILE="${DIRECTORY}/${FILENAME}.operators"
	SET_FILE="${DIRECTORY}/${FILENAME}.set"
	OBJ_FILE="${DIRECTORY}/${FILENAME}.obj"
	
	# STEP 1: Pull out operator probabilities from runtime file, save them to a separate file
	java ${JAVA_ARGS} org.moeaframework.analysis.sensitivity.ExtractData -d ${OBJCOUNT[$FINDEX]} -i ${RUNTIME_FILE} -o ${OP_PROB_FILE} NFE SBX DE PCX SPX UNDX UM
	
	# STEP 2: Remove objective values from set files and save them in *.obj files
	cut -d ' ' -f ${CUTSTART}-${CUTEND[$FINDEX]} ${SET_FILE} > ${OBJ_FILE}
	
	# STEP 3: Append pound sign (#) to the end of the final *.obj files
	echo '#' >> ${OBJ_FILE}
done

# Generate reference set
DIRECTORY="./output/O${OBJ_TYPE}_F${FORMULATIONS[$FINDEX]}"
FILE_BASE="CBorg_NCTriangle_O${OBJ_TYPE}_F${FORMULATIONS[$FINDEX]}"
REF_FILE="${DIRECTORY}/${FILE_BASE}.reference"
java ${JAVA_ARGS} org.moeaframework.util.ReferenceSetMerger -e ${EPSILONS[$FINDEX]} -o ${REF_FILE} "${DIRECTORY}/${FILE_BASE}"_*.obj

# Calculate performance metrics
for SEED in ${SEEDS}
do
	DIRECTORY="./output/O${OBJ_TYPE}_F${FORMULATIONS[$FINDEX]}"
	FILE_BASE="CBorg_NCTriangle_O${OBJ_TYPE}_F${FORMULATIONS[$FINDEX]}"
	RUNTIME_FILE="${DIRECTORY}/${FILE_BASE}_S${SEED}.runtime"
	REF_FILE="${DIRECTORY}/${FILE_BASE}.reference"
	OUTPUT_FILE="${DIRECTORY}/${FILE_BASE}_S${SEED}.metrics"

	java ${JAVA_ARGS} org.moeaframework.analysis.sensitivity.ExtractData -r ${REF_FILE} -d ${OBJCOUNT[$FINDEX]} -i ${RUNTIME_FILE} -o ${OUTPUT_FILE} NFE +generational +epsilon +hypervolume +contribution
done
