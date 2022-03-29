# *
# * Copyright (c) 2022 Brandon Pacewic
# *
# * Developed and tested by Brandon Pacewic
# * 
# * MakeFile for Simon Stores
# *

# Options
CPP = gcc
DEBUG = # -g

# Expected File Directories
INCLUDE = ../include
SRC = ../scr
MAIN = ..

# Main executable
# TODO: Create a list of all dependencies here
executable: static_mod_type.o uniform_matrix.o
	${CPP} ${DEBUG} ${MAIN}/main.cc static_mod_type.o uniform_matrix.o

static_mod_type.o:
	${CPP} ${DEBUG} -c ${SCR}/static_mod_type.cc -o static_mod_type.o

uniform_matrix.o:
	${CPP} ${DEBUG} -c ${SCR}/uniform_matrix.cc -o uniform_matrix.o

