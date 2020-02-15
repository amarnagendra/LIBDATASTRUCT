CC = gcc
TARGET  = test.o
SOURCES = ./src/list.c ../test/main.c
HEADERS = ../../
INT_HEADERS = ./interface
SRC_HEADER = ./src/
OBJECTS = $(SOURCES:.c=.o)
FLAGS = -shared

all: $(TARGET)

$(TARGET):
	$(CC) $(SOURCES) -I$(HEADERS) -I$(INT_HEADERS) -I$(SRC_HEADER) -o $(TARGET) -g

clean:
	rm $(TARGET)
