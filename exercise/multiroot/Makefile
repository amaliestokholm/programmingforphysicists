CFLAGS = -Wall -std=gnu99 -g
LDLIBS = -lm 
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
FORMAT = pdf
SCRIPT = log
PLOTTER = pyxplot
ECHO = /bin/echo

.PHONY: all plot.$(FORMAT) clean 

all : out_rosenbrock.txt plot.$(FORMAT)

R1 = 2
R2 = 3
R3 = 4
R4 = 8 
R5 = 10

out_hshot.txt : hshot Makefile
	for R in $(R1) $(R2) $(R3) $(R4) $(R5); do \
		./$< $$R | tee --append $@; \
	done

WIDTH = 8
plot.$(FORMAT) : out_hshot.txt Makefile
	$(RM) $(SCRIPT)
	$(ECHO) '\
	set term $(FORMAT); \
	set output "$@"; \
	set multiplot; \
	set title "S-wave in Hydrogen"; \
	set tics out; \
	set grid; \
	set width $(WIDTH); \
	set xlabel "Radial distance [$$a_{\mathrm{Bohr}}$$]"; \
	set ylabel "$$F_\epsilon(r)$$"; \
	plot \
	"$<" index 1 with lines title "$$r_{\mathrm{max}}$$=$(R1)" \
	,"$<" index 3 with lines title "$$r_{\mathrm{max}}$$=$(R2)" \
	,"$<" index 5 with lines title "$$r_{\mathrm{max}}$$=$(R3)" \
	,"$<" index 7 with lines title "$$r_{\mathrm{max}}$$=$(R4)" \
	,"$<" index 9 with lines title "$$r_{\mathrm{max}}$$=$(R5)" \
	,"$<" index 9 using 1:3 with lines linetype 2 title "Exact";\
	set origin 0, -$(WIDTH)-1; \
	set title "Energy as function of $$r_\mathrm{max}$$"; \
	set xlabel "$$r_\mathrm{max}$$ [$$a_\mathrm{Bohr}$$]"; \
	set ylabel "$$\epsilon$$ [Hatree]"; \
	plot [$(R1)-1:$(R5)+1][-0.6:0]\
	"$<" index 0 with points pointtype 1 color red notitle \
	,"$<" index 2 with points pointtype 1 color red notitle \
	,"$<" index 4 with points pointtype 1 color red notitle \
	,"$<" index 6 with points pointtype 1 color red notitle \
	,"$<" index 8 with points pointtype 1 color red notitle \
	,-0.5 with lines linetype 2 title "Exact"\
	' | tee $(SCRIPT) | $(PLOTTER)

out_rosenbrock.txt : rosenbrock
	./$^ > $@

rosenbrock: rosenbrock.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

hshot : hshot.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)
clean : 
	find ./ -type f -executable -delete
	$(RM) $(SCRIPT) *.pdf log* out*
