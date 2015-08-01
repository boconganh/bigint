PROG ?= main
OBJS = bigint.o main.o

all: $(PROG)

.cpp.o:
	gcc -Wall -pedantic -ggdb -O2 -c -o $@ $<

$(PROG): $(OBJS)
	gcc -Wall -pedantic -ggdb -O2 -o $@ $(OBJS)
clean:
	rm *.o