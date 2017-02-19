# make knows a lot. try 'make -p'
CFLAGS = -Wall -std=gnu99 # print out ALL warnings
LDLIBS = -lm  # links to math
SOURCES = main.c nvector.c 
OBJECTS = $(SOURCES: .c=.o)  # change the postfix from .c to .o
EXECUTEABLE = nvector

.PHONEY: out.txt clean  # To make sure that default is not a file, but an action.

out.txt : $(SOURCES) $(EXECUTEABLE)
	./$(EXECUTEABLE) > $@  # whatever main prints to the terminal is also send to out.txt

$(EXECUTEABLE): $(OBJECTS)
	cc $(OBJECTS) -o $@ $(LDLIBS)


# clean removes all temporary files, only the original files remain.
clean : 
	rm --force *.o *~ out.txt
