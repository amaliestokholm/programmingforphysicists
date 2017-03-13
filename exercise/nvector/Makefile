CFLAGS = -Wall -std=gnu99
LDLIBS = -lm 
SOURCES = main.c nvector.c 
OBJECTS = $(SOURCES: .c=.o)
EXECUTEABLE = nvector

.PHONY: out.txt clean

out.txt : $(SOURCES) $(EXECUTEABLE)
	./$(EXECUTEABLE) > $@

$(EXECUTEABLE): $(OBJECTS)
	cc $(OBJECTS) -o $@ $(LDLIBS)

clean :                                                            
	find ./ -type f -executable -delete
	$(RM) *.txt $(SCRIPT) *.pdf log*

