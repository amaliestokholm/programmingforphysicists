# make knows a lot. try 'make -p'
CFLAGS = -Wall -std=gnu99 # print out ALL warnings
LDLIBS = -lm  # links to math
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
SOURCES = main.c 
OBJECTS = $(SOURCES: .c=.o)  # change the postfix from .c to .o
EXECUTEABLE = eigen
SCRIPT = log.gpi
FORMAT = pdf
PLOTTER = gnuplot

.PHONEY: plot.$(FORMAT) clean data log # To make sure that default is not a file, but an action.

all : out.txt data log plot.$(FORMAT)

data log : main;
	./$< 1> data 2> errlog  # send standard output into 'data' and standard error into 'errlog'

plot.$(FORMAT) : Makefile
	echo 'set term $(FORMAT)' >> $(SCRIPT)
	echo 'set title "Eigen-functions"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "u(x)"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo ' "data" using "x":"u0" with lines title "u_0" \' >> $(SCRIPT)
	echo ',"data" using "x":"u1" with lines title "u_1" \' >> $(SCRIPT)
	echo ',"data" using "x":"u2" with lines title "u_2"' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out.txt : $(SOURCES) $(EXECUTEABLE)
	./$(EXECUTEABLE) > $@  # whatever main prints to the terminal is also send to out.txt

$(EXECUTEABLE): $(OBJECTS)
	cc $(OBJECTS) -o $@ $(LDLIBS)


# clean removes all temporary files, only the original files remain.
clean : 
	find ./ -type f -executable -delete
	$(RM) *.dat $(SCRIPT) *.svg *.png *.pdf log*
