###############################################################################
#
#	This is a template for a makefile that can be used with C or C++, to
#	convert between languages change  PREFIX=C_OR_CPP to the file extension of
#	choice (c|cpp).
#
#	This makefile is meant to be used in a directory structure shown below:
#		project_dir/
#    	├── LICENSE
#    	├── Makefile
#    	├── README.md
#    	├── doxygen.conf
#    	├── doc/
#    	├── include/
#    	|   └── src.h
#    	├── src/
#    	│   └── src.c
#    	└── test/
#
#	It will make the obj and build dir for you, and will delete these in order
#	to clean the project. This way it is all contained in top level directories
#	and there can be no confusion with rm *.o
#
###############################################################################

# Dirs that should already exist
SRC_DIR=src
INCLUDE_DIR=include

# Dirs that are created
BUILD_DIR=build
OBJ_DIR=obj

# Commands to use
CC:=gcc

# Compile information
TARGET=Hangman
COMPILE_FLAGS=-g -Wall -Werror -I${INCLUDE_DIR}
LINK_FLAGS=
LIBS= -pthread

# File prefix
PREFIX=c

# Gathering files
SRC_FILES := $(wildcard ${SRC_DIR}/*.${PREFIX})
OBJ_FILES := $(subst ${SRC_DIR},${OBJ_DIR},$(patsubst %.${PREFIX},%.o,$(wildcard ${SRC_DIR}/*.${PREFIX})))

# Rules
all: ${TARGET}

${TARGET}: BUILD_DIR OBJ_DIR ${OBJ_FILES}
	@echo "Linking : ${TARGET}"
	@${CC} ${OBJ_FILES} -o ${BUILD_DIR}/${TARGET} ${LINK_FLAGS} ${LIBS}

BUILD_DIR:
	@mkdir -p ${BUILD_DIR}

OBJ_DIR:
	@mkdir -p ${OBJ_DIR}

define SRC_RULE
$(subst ${SRC_DIR},${OBJ_DIR},$(subst .${PREFIX},.o,$(1))): $(1)
	@echo "Compiling: $(subst ${SRC_DIR}/,,$(1))"
	@${CC} -c $(1) -o $(subst ${SRC_DIR},${OBJ_DIR},$(subst .${PREFIX},.o,$(1))) ${COMPILE_FLAGS}
endef
$(foreach FILE,${SRC_FILES},$(eval $(call SRC_RULE,${FILE})))

# Utility commands

.PHONY: analyze
analyze: clean
	@scan-build make

.PHONY: doc
doc:
	@doxygen doxygen.conf

.PHONY: clean
clean:
	@rm -rf ${BUILD_DIR}
	@rm -rf ${OBJ_DIR}

.PHONY: lint
lint:
	@clang-tidy --config=clang_tidy.conf src/*

.PHONY: run
run: ${TARGET}
	@${BUILD_DIR}/${TARGET}

.PHONY: help
help:
	@echo "Targets of this Makefile:"
	@echo "  all		Build main target: ${TARGET}"
	@echo "  analyze	Statically analyze the project src code, cleans first"
	@echo "  BUILD_DIR	Create ${BUILD_DIR}"
	@echo "  clean		Cleans project by removing ${BUILD_DIR} and ${OBJ_DIR}"
	@echo "  doc		Builds the documentation for this project"
	@echo "  help		Prints out this help information"
	@echo "  lint		Lints the project with clang-tidy"
	@echo "  OBJ_DIR	Create ${OBJ_DIR}"
	@echo "  run		Runs: ${TARGET}"