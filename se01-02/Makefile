CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGETS = prog22 prog24 prog26 filter str02

all: $(TARGETS)

prog22: prog22.o func.o
	$(CC) $(CFLAGS) -o prog22 prog22.o func.o

prog24: prog24.o func.o
	$(CC) $(CFLAGS) -o prog24 prog24.o func.o

prog26: prog26.o func.o
	$(CC) $(CFLAGS) -o prog26 prog26.o func.o

filter: filter.o func.o
	$(CC) $(CFLAGS) -o filter filter.o func.o

str02: str02.o func.o
	$(CC) $(CFLAGS) -o str02 str02.o func.o

prog22.o: prog22.c func.h
	$(CC) $(CFLAGS) -c prog22.c func.h

prog24.o: prog24.c func.h
	$(CC) $(CFLAGS) -c prog24.c func.h

prog26.o: prog26.c func.h
	$(CC) $(CFLAGS) -c prog26.c func.h

filter.o: filter.c func.h
	$(CC) $(CFLAGS) -c filter.c func.h

str02.o: str02.c func.h
	$(CC) $(CFLAGS) -c str02.c func.h

func.o: func.c func.h
	$(CC) $(CFLAGS) -c func.c func.h

clean:
	rm -f $(TARGETS) *.o

.PHONY: all clean