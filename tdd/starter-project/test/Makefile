# we don’t want to use relative paths, so we set these variables
PROJECT_DIR=/workspace/work/my/study/DailyCoding/tdd/starter-project
SRC_DIR=$(PROJECT_DIR)/src
TEST_DIR=$(PROJECT_DIR)/test
# specify where the source code and includes are located
INCLUDE_DIRS=$(SRC_DIR)/code
SRC_DIRS=$(SRC_DIR)/code
 
# specify where the test code is located
TEST_SRC_DIRS = $(TEST_DIR)
 
# what to call the test binary
TEST_TARGET=example

# where the cpputest library is located
export CPPUTEST_HOME=/workspace/work/my/study/DailyCoding/tdd/tools/cpputest-3.8
INCLUDE_DIRS=$(SRC_DIR)/code $(CPPUTEST_HOME)/include

# run MakefileWorker.mk with the variables defined here
include MakefileWorker.mk
