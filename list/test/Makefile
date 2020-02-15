CC = gcc
TARGET  = linkedlist_test.out
SOURCES = ./main.c
HEADERS = ../../
INT_HEADERS = ../single/interface
LIBS = -llinkedlist.so
LPATH = ../single
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET):
	$(CC) $(SOURCES) -I$(HEADERS) -I$(INT_HEADERS) -L$(LPATH) $(LIBS) -o $(TARGET) 

clean:
	rm $(TARGET)
