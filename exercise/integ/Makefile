CFLAGS = -Wall -std=gnu99 
LDLIBS = -lm 
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
FORMAT = pdf
SCRIPT = log
PLOTTER = gnuplot
SOURCES = lnsqrt

.PHONEY: all plot.$(FORMAT) clean 

all : out_lnsqrt.txt  #plot.$(FORMAT)

plot.$(FORMAT) : out_error.txt Makefile
	echo 'set term $(FORMAT)' >> $(SCRIPT)
	echo 'set title "Orbital motion"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set size ratio -1' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "y"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$(word 1, $^)" using "t":"y(t)" with lines notitle \' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out_lnsqrt.txt : lnsqrt
	./$^ > $@

lnsqrt : lnsqrt.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)
clean : 
	find ./ -type f -executable -delete
	$(RM) *.dat $(SCRIPT) *.svg *.png *.pdf log*