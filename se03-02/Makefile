CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = app

# Source files
SRCS = app.c bookModule.c vecModule.c dynModule.c lRefModule.c bstModule.c string.c pergunta1.c pergunta2.c procTextFile.c SE1.c func2.c funcSE1.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean