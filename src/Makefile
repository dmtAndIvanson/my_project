CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LIBS = decimal.c
BUILDING_FILE = tmp.c
TARGET_NAME = tmp

all: clean build

build:
	$(CC) $(CFLAGS) $(LIBS) $(BUILDING_FILE) -o $(TARGET_NAME)

clean:
	rm -rf *.o $(TARGET_NAME) *.a