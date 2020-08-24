#!/bin/bash

FILE=$1
TARGET=${FILE##*/}
NAME=${TARGET%%.*}
BIN=test_$NAME

GSL_LIB_INC=$PWD/gsl/include

rm -f ./$BIN
gcc -o $BIN $1 -I$GSL_LIB_INC -lstdc++
./$BIN
