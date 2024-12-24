CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = prog12
OBJS = prog01.o prog12.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

prog01.o: prog01.c prog01.h
	$(CC) $(CFLAGS) -c prog01.c

prog12.o: prog12.c prog01.h
	$(CC) $(CFLAGS) -c prog12.c

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean