SRCS = $(wildcard *.cs)

PROGS = $(patsubst %.cs,%,$(SRCS))

all: $(PROGS)

%: %.cs
	mcs -out:$@.exe $<
