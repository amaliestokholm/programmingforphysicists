CFLAGS = -Wall -std=gnu99
LDFLAGS = -lm 

.PHONY: all clean  # To make sure that default is not a file, but an action.

all : out.txt
	cat out.txt

epsilon : epsilon.c
	cc $(CFLAGS) epsilon.c equal.c -o epsilon

out.txt : epsilon
	./epsilon > out.txt  # Whatever main prints to the terminal is also send to out.txt

clean :                                                            
	        find ./ -type f -executable -delete
		        $(RM) *.txt $(SCRIPT) *.pdf log*
