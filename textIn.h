#ifndef TEXT_H
#define TEXT_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"HMAC.c"
#include<stdint.h>
#include<openssl/rand.h>
int chaffing(FILE *in,FILE *out,const char* key);
int windowing(FILE *in, FILE *out,const char* key);
unsigned int random_uint(unsigned int limit);
#endif
