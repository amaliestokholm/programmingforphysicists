CFLAGS = -Wall -std=gnu99 # print out ALL warnings
LDLIBS = -lm  # links to math
SOURCES = math.c 
OBJECTS = $(SOURCES: .c=.o)  # change the postfix from .c to .o
EXECUTEABLE = math

.PHONY: out.txt clean  # To make sure that default is not a file, but an action.

out.txt : $(SOURCES) $(EXECUTEABLE)
	./$(EXECUTEABLE) > $@  # whatever main prints to the terminal is also send to out.txt

$(EXECUTEABLE): $(OBJECTS)
	cc $(OBJECTS) -o $@ $(LDLIBS)

clean :                                                            
	find ./ -type f -executable -delete
	$(RM) *.txt $(SCRIPT) *.pdf log*
