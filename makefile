Wall = -Wall
CC = gcc
AR = ar

.PHONY : all clean


all : prog



prog : lib_str_mainpulation.a main.o
	${CC}  ${Wall} -o prog str_mainpulation.o  main.o



lib_str_mainpulation.a : str_mainpulation.o
	${AR} -rcs lib_str_mainpulation.a str_mainpulation.o



str_mainpulation.o : str_mainpulation.c str_mainpulation.h
	${CC}  ${Wall} -c str_mainpulation.c


main.o : main.c str_mainpulation.h 
	${CC}  ${Wall} -c main.c 


clean : 
	rm -rf *.o prog  *.a