#!/bin/bash

# 6 formulations (0 - 5)
FORMULATIONS=("0" "1" "2" "3" "4" "5" "6")

# Objective Types: 0 (Max value among utilities) or 1 (average value across utilities)
OBJ_TYPES=$(seq 0 2)

for OBJ_TYPE in ${OBJ_TYPES}
do
	for FINDEX in ${!FORMULATIONS[*]}
	do
		qsub -N PostProcessing_O${OBJ_TYPE}_F${FORMULATIONS[$FINDEX]} -v FINDEX=${FINDEX},OBJ_TYPE=${OBJ_TYPE} postProcessing.sh
	done
done
