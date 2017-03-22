FLAGS = -Wall -std=gnu99
LDLIBS = -lm
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
FORMAT = pdf
SCRIPT = log
PLOTTER = gnuplot

.PHONY: all plot.$(FORMAT) clean

all : out.txt #plot.$(FORMAT)

plot.$(FORMAT) : out_hshot.txt Makefile
	$(RM) $(SCRIPT)
	$(ECHO) '\
	set term $(FORMAT); \
	set output "$@"; \
	set title "Bessel function "; \
	set tics out; \
	set grid; \
	set xlabel "x"; \
	set ylabel "$$J_n(x)$$"; \
	plot \
	"$<" index 1 with lines title "Calculated" \
	,"$<" index 3 with lines title "Exact" \
	' | tee $(SCRIPT) | $(PLOTTER)


out.txt : jn
	./$^ > $@

jn : jn.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

clean : 
	find ./ -type f -executable -delete
	$(RM) *.txt $(SCRIPT) *.pdf 
