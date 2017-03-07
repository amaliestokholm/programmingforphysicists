CFLAGS = -Wall -std=gnu99 
LDLIBS = -lm 
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
FORMAT = pdf
SCRIPT = log
PLOTTER = gnuplot

.PHONEY: all plot.$(FORMAT) clean 

all : out_lnsqrt.txt plot.$(FORMAT)

plot.$(FORMAT) : out_integ.txt Makefile
	echo 'set term $(FORMAT)' >> $(SCRIPT)
	echo 'set title "Energies from the variational method"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'set xlabel "Alpha"' >> $(SCRIPT)
	echo 'set ylabel "Energy"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$(word 1, $^)" using "a":"E(a)" with lines notitle \' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out_lnsqrt.txt : lnsqrt
	./$^ > $@

out_integ.txt : integ
	./$^ > $@

lnsqrt : lnsqrt.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

integ : integ.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)
clean : 
	find ./ -type f -executable -delete
	$(RM) *.dat $(SCRIPT) *.svg *.png *.pdf log*
