# make knows a lot. try 'make -p'
CFLAGS = -Wall -std=gnu99 # print out ALL warnings
LDLIBS = -lm  # links to math
SCIPT = log.gpi

.PHONEY: all out.txt clean  # To make sure that default is not a file, but an action.

all: main-stdio test.io.out.txt

main-stdio : main-stdio.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

test.io.out.txt: in.dat main-stdio
	./$(word 2, $^) < $< > $@

in.dat : Makefile
	cat /dev/null > $@
	for x in `seq 0 0.5 2`; do echo $$x >> $@; done


# clean removes all temporary files, only the original files remain.
clean : 
	find ./ -type f -executable -delete
	$(RM) *.dat $(SCRIPT) *.svg *.png *.pdf log*
