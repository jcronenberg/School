SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,%,$(SRCS))

all: $(PROGS)

%: %.cpp
	g++ $(CFLAGS)  -o $@ $<

clean:
	rm -f $(PROGS)
