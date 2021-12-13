

.PHONY = all 


all : p



p: str_mainpulation.o main.o
	gcc  -Wall -o p str_mainpulation.o  main.o




str_mainpulation.o : str_mainpulation.c str_mainpulation.h
	gcc -Wall -c str_mainpulation.c



main.o : main.c str_mainpulation.h 
	gcc -Wall -c main.c 