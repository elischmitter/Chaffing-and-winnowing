#ifndef HMAC_H
#define HMAC_H

#include <openssl/md5.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int checkHMAC(char* message,char* key,char* recevedMAC);

void  makeHMAC(char* message, char* key,char* MAC,int blockSize);

#endif
