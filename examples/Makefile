# The compiler to use
# CCPREFIX=/home/bioboost/rpi-tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-
CC=$(CCPREFIX)g++

# Compiler flags
CFLAGS=-Wall -std=c++11
    # -c: Compile or assemble the source files, but do not link. The linking stage simply is not done. The ultimate output is in the form of an object file for each source file.
    # -Wall: This enables all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning), even in conjunction with macros.

# LDFLAGS=

# Libraries
LIBS=-lbioslogger

all:
	$(CC) $(CFLAGS) $(LIBS) json_logging.cpp -o json_logging
