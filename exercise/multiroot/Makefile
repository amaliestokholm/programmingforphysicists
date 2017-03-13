CFLAGS = -Wall -std=gnu99 -g
LDLIBS = -lm 
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
FORMAT = pdf
SCRIPT = log
PLOTTER = gnuplot

.PHONEY: all plot.$(FORMAT) clean 

all : out_rosenbrock.txt #plot.$(FORMAT)

plot.$(FORMAT) : out_leastsquares.txt Makefile
	echo 'set term $(FORMAT)' >> $(SCRIPT)
	echo 'set title "Least-squares fit to data"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'set xlabel "Time"' >> $(SCRIPT)
	echo 'set ylabel "Activity"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$(word 1, $^)" index 0 with errorbars title "Experiment" \' >> $(SCRIPT)
	echo ', "$(word 1, $^)" index 1 with lines title "Model"' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out_rosenbrock.txt : rosenbrock
	./$^ > $@

rosenbrock: rosenbrock.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

hej : main.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)
clean : 
	find ./ -type f -executable -delete
	$(RM) *.dat $(SCRIPT) *.svg *.png *.pdf log*
