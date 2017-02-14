# make knows a lot. try 'make -p'
CFLAGS = -Wall -std=gnu99 # print out ALL warnings
LDFLAGS = -lm  # links to math
# makefiles thinks everything is strings by default. Valuables have a dollar sign infront.
.PHONEY: all clean  # To make sure that default is not a file, but an action.

all : out.txt
	cat out.txt

epsilon : epsilon.c
	cc $(CFLAGS) epsilon.c equal.c -o epsilon

out.txt : epsilon #/* Output from the problem. Out.txt is our 'dish', main is our function */
	./epsilon > out.txt #/* whatever main prints to the terminal is also send to out.txt */

# clean removes all temporary files, only the original files remain.
clean : 
	rm --force epsilon.o epsilon out.txt
