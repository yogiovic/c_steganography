# DU1 - Makefile
# Autor: Adam Ondrejka (xondre12)
# 17.3.2020

CC=gcc
CFLAGS= -std=c11 -Wall -pedantic -Wextra -Werror -O2
PROGS= primes primes-i steg-decode
PRIMES= primes primes-i

#---------------------------------------------------------------#

all: $(PROGS)

run: $(PRIMES)
	ulimit -s 65000 && ./primes && ./primes-i

primes: error.o primes.o eratosthenes.o bitset.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

primes-i: primes-i.o error.o bitset-i.o eratosthenes-i.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

steg-decode: steg-decode.o ppm.o error.o bitset.o eratosthenes.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

#---------------------------------------------------------------#

bitset.o: bitset.c
	$(CC) $(CFLAGS) -c $^ -o $@

bitset-i.o: bitset.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c $^ -o $@

eratosthenes.o: eratosthenes.c
	$(CC) $(CFLAGS) -c $^ -o $@

eratosthenes-i.o: eratosthenes.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c $^ -o $@

primes.o: primes.c
	$(CC) $(CFLAGS) -c $^ -o $@

primes-i.o: primes.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c $^ -o $@

ppm.o: ppm.c
	$(CC) $(CFLAGS) -c $^ -o $@

steg-decode.o: steg-decode.c
	$(CC) $(CFLAGS) -c $^ -o $@

error.o: error.c
	$(CC) $(CFLAGS) -c $^ -o $@

#---------------------------------------------------------------#

clean:
	rm *.o primes primes-i steg-decode

pack:
	zip xondre12.zip *.c *.h Makefile
