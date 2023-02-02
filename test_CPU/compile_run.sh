cd ../src_CPU
make
cd ../test_CPU
make buffer_test
qsub run.sh