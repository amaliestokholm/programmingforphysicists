# make knows a lot. try 'make -p'
CFLAGS = -Wall -std=gnu99 # print out ALL warnings
LDFLAGS = -lm  # links to math
# makefiles thinks everything is strings by default. Valuables have a dollar sign infront.
.PHONEY: default clean  # To make sure that default is not a file, but an action.

default : out.txt
	cat out.txt

out.txt : main #/* Output from the problem. Out.txt is our 'dish', main is our function */
	./main > out.txt #/* whatever main prints to the terminal is also send to out.txt */
	
#main : main.o
#	cc main.o -o main

#main.o : main.c
#	cc -c main.c

# clean removes all temporary files, only the original files remain.
clean : 
	rm --force main.o main out.txt
