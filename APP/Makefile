CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
OBJFILES = application.o bookModule.o vecModule.o dynModule.o Serie1.o Serie2.o
TARGET = application

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

application.o: application.c bookModule.h vecModule.h dynModule.h Serie1.h Serie2.h
	$(CC) $(CFLAGS) -c application.c

bookModule.o: bookModule.c bookModule.h
	$(CC) $(CFLAGS) -c bookModule.c

vecModule.o: vecModule.c vecModule.h bookModule.h
	$(CC) $(CFLAGS) -c vecModule.c

dynModule.o: dynModule.c dynModule.h vecModule.h bookModule.h
	$(CC) $(CFLAGS) -c dynModule.c

Serie1.o: Serie1.c Serie1.h
	$(CC) $(CFLAGS) -c Serie1.c

Serie2.o: Serie2.c Serie2.h
	$(CC) $(CFLAGS) -c Serie2.c

clean:
	rm -f $(OBJFILES) $(TARGET)