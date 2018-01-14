PROGS = simple static_cast dynamic_cast

run: $(PROGS)
	@for PROG in $(PROGS); do\
		./$${PROG}; \
	done

CC = g++
CCFLAGS = -std=c++11 -Wall

%: %.cc.o
	$(CC) $^ $(CLFLAGS) -o $@

%.cc.o : %.cc
	$(CC) $(CCFLAGS) -c $< -o $@
