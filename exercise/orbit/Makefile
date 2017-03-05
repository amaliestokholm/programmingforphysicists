CFLAGS = -Wall -std=gnu99 
LDLIBS = -lm 
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
SOURCES = orbit.c ydiff.c
OBJECTS = $(SOURCES: .c=.o)
EXECUTEABLE = orbit ydiff
FORMAT = pdf
PLOTTER = gnuplot

.PHONEY: all plot.$(FORMAT) clean 

all : out_ydiff.txt out_orbit.txt  # plot.$(FORMAT) data

plot.$(FORMAT) : out_orbit.txt Makefile
	echo 'set term $(FORMAT)' >> $(SCRIPT)
	echo 'set title "Orbital motion"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "y"' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out_ydiff.txt : ydiff 
	./$< >$@  # send standard output into 'data'

out_orbit.txt : orbit
	./$< > $@

$(EXECUTEABLE): $(OBJECTS)
	cc $(OBJECTS) -o $@ $(CFLAGS) $(LDLIBS)

clean : 
	find ./ -type f -executable -delete
	$(RM) *.dat $(SCRIPT) *.svg *.png *.pdf log*
