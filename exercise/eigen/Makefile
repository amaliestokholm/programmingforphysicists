CFLAGS = -Wall -std=gnu99 
LDLIBS = -lm 
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
SOURCES = main.c 
OBJECTS = $(SOURCES: .c=.o)
EXECUTEABLE = eigen
SCRIPT = log.gpi
FORMAT = pdf
PLOTTER = gnuplot

.PHONY: all plot.$(FORMAT) clean 

all : plot.$(FORMAT) data

plot.$(FORMAT) : data Makefile
	echo 'set term $(FORMAT)' >> $(SCRIPT)
	echo 'set title "Eigen-functions"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "u(x)"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo ' "$(word 1,$^)" using "x":"u0" with lines title "u_0" \' >> $(SCRIPT)
	echo ',"$(word 1,$^)" using "x":"u1" with lines title "u_1" \' >> $(SCRIPT)
	echo ',"$(word 1,$^)" using "x":"u2" with lines title "u_2"' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

data : $(EXECUTEABLE)
	./$< >$@ 

$(EXECUTEABLE): $(OBJECTS)
	cc $(OBJECTS) -o $@ $(CFLAGS) $(LDLIBS)

clean :                                                            
	find ./ -type f -executable -delete
	$(RM) data *.txt $(SCRIPT) *.pdf log*

