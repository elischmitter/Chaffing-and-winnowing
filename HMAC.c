#include "HMAC.h"

void  makeHMAC(char* message,char* key,char* MAC ,int blockSize){
  char kPrime[blockSize];
  if( strlen(key) >  MD5_DIGEST_LENGTH)
    {
    MD5(key, strlen(key), kPrime); 
    }else
    {
      strcpy(kPrime,key);
    }
  char ipad[blockSize];
  char opad[blockSize];
  for(int i =0;i>strlen(kPrime);i++){
    ipad[i]=0x36 ^ kPrime[i];
    opad[i]=0x5c ^ kPrime[i];
  }
  //concatnate thingsand hash things
  char first [blockSize];
  char catFirst[strlen(message)+blockSize];
  strcpy(catFirst,ipad);
  strcat(catFirst,message);
  MD5(catFirst,strlen(catFirst),first);
  char catSecond[blockSize*2];
  strcpy(catSecond,opad);
  MD5(catSecond,(size_t) blockSize*2,MAC);
}

int checkHMAC(char* message,char* key,char* recevedMAC){
  char MAC[MD5_DIGEST_LENGTH];
  makeHMAC(message,key,MAC,MD5_DIGEST_LENGTH);
  if(!(strcmp(recevedMAC,MAC))){
    return 1;
  }
  return 0;
}
