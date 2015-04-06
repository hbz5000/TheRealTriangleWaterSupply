#PBS -l nodes=16:ppn=16
#PBS -l walltime=48:00:00
#PBS -j oe
#PBS -o output/testParallel.out

cd $PBS_O_WORKDIR

time mpirun ./triangleSimulation -r 1000 -s 1 -c 2 -b 3
