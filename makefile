CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -O1 -g
LDFLAGS = -lm -lcrypto
.PHONY: clean 
.DEFAULT_GOAL:= HMAC.o

HMAC.o: HMAC.c
	${CC} ${CFLAGS} -o HMAC.o -c  HMAC.c ${LDFLAGS}
textIn.o:
	${CC} ${CFLAGS} -o textIn.o  textIn.c ${LDFLAGS}


clean:
	rm *.o
