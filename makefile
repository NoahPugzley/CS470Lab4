CC = gcc
CFLAGS = -Wall -Wextra -O2

libFS: Noah_LibFS.c
	$(CC) $(CFLAGS) -o libFS Noah_LibFS.c

clean:
	rm -f libFS