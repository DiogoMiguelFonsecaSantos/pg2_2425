# Compiler and flags
# CC is the compiler to be used, gcc
CC = gcc

# CFLAGS are the flags passed to the compiler
# -Wall enables all compiler's warning messages
# -Wextra enables some extra warning flags that are not enabled by -Wall
CFLAGS = -Wall -Wextra  

# Targets executable names
# TARGETS are the names of the final executable files
TARGETS = prog24 prog26

# Source files and corresponding object files
# SRC lists all the source files (.c) in the project.
SRC_PROG24 = prog24.c procTextFile.c funcSE1.c func2.c
SRC_PROG26 = prog26.c procTextFile.c funcSE1.c func2.c

# OBJ lists all the object files (.o) corresponding to the source files.
# The substitution reference $(SRC:.c=.o) replaces the .c extension with .o.
OBJ_PROG24 = $(SRC_PROG24:.c=.o)
OBJ_PROG26 = $(SRC_PROG26:.c=.o)

# Header dependencies
# DEPS lists the header files (.h) that the source files depend on.
DEPS = procTextFile.h funcSE1.h func2.h

# Default target
# The 'all' target is the default target that will be built when 'make' is run without arguments.
# It depends on the $(TARGET), so it will build the target executable.
all: $(TARGETS)

# Rule to build the target executable
# This rule specifies how to build the target executable from the object files.
# $@ is an automatic variable that represents the target (in this case, $(TARGET)).
# $^ is an automatic variable that represents all the prerequisites (in this case, $(OBJ)).

# Build prog24
prog24: $(OBJ_PROG24)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build prog26
prog26: $(OBJ_PROG26)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile object files, including header dependencies
# This rule specifies how to compile each .c file into a .o file.
# $< is an automatic variable that represents the first prerequisite (in this case, the .c file).
# $@ is an automatic variable that represents the target (in this case, the .o file).
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
# The 'clean' target removes the object files and the target executable.
clean:
	rm -f $(OBJ_PROG24) $(OBJ_PROG26) $(TARGETS)
