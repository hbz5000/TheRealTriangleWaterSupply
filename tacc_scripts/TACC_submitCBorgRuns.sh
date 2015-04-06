#!/bin/bash

# 6 formulations (0 - 5)
FORMULATIONS=$(seq 0 6)

# Objective Types: 0 (Max value among utilities) or 1 (average value across utilities)
OBJ_TYPES=$(seq 0 2)

for OBJ_TYPE in ${OBJ_TYPES}
do
	for FORMULATION in ${FORMULATIONS}
	do
		qsub -N CBorg_NCTriangle_O${OBJ_TYPE}_F${FORMULATION} -v FORMULATION=${FORMULATION},OBJ_TYPE=${OBJ_TYPE} TACC_run50Seeds.sh
	done
done
