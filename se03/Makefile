CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS =

# Source files
SRCS = app.c bookModule.c vecModule.c dynModule.c lRefModule.c bstModule.c SE1.c SE2.c
# Header files
HDRS = bookModule.h vecModule.h dynModule.h lRefModule.h bstModule.h SE1.h SE2.h
# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = app

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean