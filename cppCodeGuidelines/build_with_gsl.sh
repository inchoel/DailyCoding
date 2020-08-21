#!/bin/bash

BIN=test_$1
GSL_LIB_INC=$PWD/gsl/include

echo $BIN
echo $GSL_LIB_INC

gcc -o $BIN $1 -I$GSL_LIB_INC -lstdc++
