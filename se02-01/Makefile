CC = gcc
CFLAGS = -Wall
PROG13_F = prog13_f
PROG15_F = prog15_f
PROG13 = prog13
PROG15 = prog15
OBJS_COMMON = lineprint.o process.o linefilter.o

all: $(PROG13_F) $(PROG15_F) $(PROG13) $(PROG15)

# Targets for prog13_f
$(PROG13_F): prog13_f.o $(OBJS_COMMON)
	$(CC) prog13_f.o $(OBJS_COMMON) -o $(PROG13_F)

prog13_f.o: prog13_f.c prog13_f.h
	$(CC) $(CFLAGS) -c prog13_f.c

# Targets for prog15_f
$(PROG15_F): prog15_f.o $(OBJS_COMMON)
	$(CC) prog15_f.o $(OBJS_COMMON) -o $(PROG15_F)

prog15_f.o: prog15_f.c prog13_f.h
	$(CC) $(CFLAGS) -c prog15_f.c

# Targets for prog13
$(PROG13): prog13.o $(OBJS_COMMON)
	$(CC) prog13.o $(OBJS_COMMON) -o $(PROG13)

prog13.o: prog13.c prog13.h
	$(CC) $(CFLAGS) -c prog13.c

# Targets for prog15
$(PROG15): prog15.o $(OBJS_COMMON)
	$(CC) prog15.o $(OBJS_COMMON) -o $(PROG15)

prog15.o: prog15.c prog13.h
	$(CC) $(CFLAGS) -c prog15.c

# Common object files
lineprint.o: lineprint.c prog13_f.h
	$(CC) $(CFLAGS) -c lineprint.c

process.o: process.c prog13_f.h
	$(CC) $(CFLAGS) -c process.c

linefilter.o: linefilter.c
	$(CC) $(CFLAGS) -c linefilter.c

clean:
	rm -f *.o $(PROG13_F) $(PROG15_F) $(PROG13) $(PROG15)

.PHONY: all clean