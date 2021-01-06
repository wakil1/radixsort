# Wakil Nooristany G01077677
# CS 262, Lab Section 208
#Project 3
# The compiler: gcc for C programs, g++ for c++ programs, etc
CC = gcc

CFLAGS = -Wall -g -std=c89 -D_XOPEN_SOURCE=600 -pedantic-errors
TARGET = Project3

LIBS=-lm

all: $(TARGET)
		$(CC) $(CLFAGS) -o $(TARGET) $(TARGET).c

clean:
		rm $(TARGET)

