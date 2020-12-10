SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,%,$(SRCS))

all: $(PROGS)

%: %.cpp
	g++ $(CFLAGS)  -g -o $@ $<

clean:
	rm -f $(PROGS)
