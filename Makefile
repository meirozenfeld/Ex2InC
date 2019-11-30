# -*- Makefile -*-
CC=gcc
AR=ar
OBJECTS_Main=main.o
OBJECTS_Bank=myBank.o
FLAGS= -Wall -g

all: libmylib main

libmylib: $(OBJECTS_Bank)
	$(AR) -rcs libmylib $(OBJECTS_Bank)	
       
main: $(OBJECTS_Bank) $(OBJECTS_Main) 
	$(CC) $(FLAGS) -o main $(OBJECTS_Bank) $(OBJECTS_Main) 	

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
	
main.o: main.c myBank.h  
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o main




