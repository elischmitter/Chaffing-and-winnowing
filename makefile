CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -O1 -g
LDFLAGS = -lm -lcrypto

all:
	${CC} ${CFLAGS} HMAC.c ${LDFLAGS}


clean:
	rm *.o
