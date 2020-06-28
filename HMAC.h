#ifndef HMAC_H
#define HMAC_H

int checkHMAC(char* message,char* key,char* receveMAC);

char*  makeHMAC(char* message, char* key);

#endif
