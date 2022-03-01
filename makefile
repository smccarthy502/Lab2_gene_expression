

CC = g++
SHELL = /bin/bash
CFLAGS = -fPIC 

INCDIR = -I"/home/mccarts/Lab2/"
LIBDIR = "/home/mccarts/Lab2/"
LDFLAGS = -L"/home/mccarts/Lab2/"

mccarthy_stats.o: mccarthy_stats.cpp mccarthy_stats.hpp
	$(CC) $(CFLAGS) -c $^ -lm

libstats.so: mccarthy_stats.o
	$(CC) -shared $< -o $@

mccarthys_vector_ops.o: mccarthys_vector_ops.cpp mccarthys_vector_ops.hpp
	$(CC) $(CFLAGS) -c $(INCDIR) $^ -lm

libvector_ops.so: mccarthys_vector_ops.o
	$(CC) -shared $^ -o $@

preprocessing: mccarthys_pre_processing.cpp 
	$(CC) $(CFLAGS) -o $@ $^ -Wl,-rpath=$(LIBDIR) $(LDFLAGS) -lvector_ops -lstats

test: test.cpp
	 $(CC) $(CFLAGS) -o $@ $^ -Wl,-rpath=$(LIBDIR) $(LDFLAGS) -lvector_ops

clustering: mccarthys_k_means.cpp mccarthys_k_means.hpp
	$(CC) $(CFLAGS) -o $@ $^ -Wl,-rpath=$(LIBDIR) $(LDFLAGS) -lm -lstats

clean:
	rm mccarthy_stats.o
	rm libstats.so
	rm mccarthys_vector_ops.o
	rm libvector_ops.so
	rm preprocessing
	rm test
