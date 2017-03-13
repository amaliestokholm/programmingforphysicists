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

WIDTH = 5
plot.$(FORMAT) : out_hshot.txt Makefile
	$(RM) $(SCRIPT)
	echo 'set term $(FORMAT)' >> $(SCRIPT)
	echo 'set title "S-wave in Hydrogen"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'set xlabel "Radial distance [$$a_{\mathrm{Bohr}}$$]"' >> $(SCRIPT)
	echo 'set ylabel "$$F_\epsilon(r)$$"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$<" index 1 with lines title "$$r_{\mathrm{max}}$$=$(R1)" \' >> $(SCRIPT)
	echo ',"$<" index 3 with lines title "$$r_{\mathrm{max}}$$=$(R2)" \' >> $(SCRIPT)
	echo ',"$<" index 5 with lines title "$$r_{\mathrm{max}}$$=$(R3)" \' >> $(SCRIPT)
	echo ',"$<" index 7 with lines title "$$r_{\mathrm{max}}$$=$(R4)" \' >> $(SCRIPT)
	echo ',"$<" index 9 with lines title "$$r_{\mathrm{max}}$$=$(R5)" \' >> $(SCRIPT)
	echo ',"$<" index 9 using 1:3 with lines linetype 2 title "Exact"; ' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out_rosenbrock.txt : rosenbrock
	./$^ > $@

rosenbrock: rosenbrock.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

hshot : hshot.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)
clean : 
	find ./ -type f -executable -delete
	$(RM) $(SCRIPT) *.pdf log* out*
