SHELL	= /bin/sh
CC		= clang

FLAGS	= -std=gnu99
CFLAGS	= -pedantic -Wall -Wextra

TARGET	= bin/vonti
SOURCES	= $(shell echo src/*.c)
OBJECTS = $(SOURCES:.c=.o)

DEPS = -lm -g
SDL = `sdl2-config --cflags --libs`

all: build

build:
	$(CC) $(FLAGS) $(CFLAGS) -o $(TARGET) $(SOURCES) $(SDL) $(DEPS)
