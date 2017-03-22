FLAGS = -Wall -std=gnu99
LDLIBS = -lm
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
ECHO = /bin/echo
FORMAT = pdf
SCRIPT = log
PLOTTER = pyxplot

.PHONY: all plot.$(FORMAT) clean

all : plot.$(FORMAT)

plot.$(FORMAT) : out.txt Makefile
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
	"$<" index 0 with points title "Calculated" \
	, "$<" index 1 with points title "Exact" \
	' | tee $(SCRIPT) | $(PLOTTER)

out.txt : jn
	./$^ > $@

jn : jn.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

clean : 
	find ./ -type f -executable -delete
	$(RM) *.txt $(SCRIPT) *.pdf 
