#ifndef HMAC_H
#define HMAC_H

#include <openssl/ripemd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int checkHMAC(char* message,char* key,  char* recevedMAC);

void  makeHMAC(const char* message,const char* key, unsigned char* MAC,int blockSize);

#endif
