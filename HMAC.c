#include "HMAC.h"

void  makeHMAC(const char* message, const char* key,unsigned char*  MAC ,int blockSize){
  unsigned char kPrime[blockSize];
  if( strlen(key) > 20)
    {
      RIPEMD160((const unsigned char*) key, (unsigned long ) strlen(key),kPrime); 
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
  RIPEMD160((const unsigned char*) catFirst,(unsigned long )strlen(catFirst),first);
  char catSecond[blockSize*2];
  strcpy(catSecond,opad);
  RIPEMD160((const unsigned char*) catSecond, (unsigned long )blockSize*2,MAC);
}

int checkHMAC(char* message,char* key,unsigned char* recevedMAC){
  unsigned char MAC[20];
  makeHMAC(message,key,MAC,20);
    printf("%s",MAC);
   printf("\n");
  return((strcmp(recevedMAC,MAC)));
}
void main(){
unsigned char MAC[20];
 makeHMAC("123","123",MAC,20);
 printf("%s",MAC);
 printf("\n");
 printf("%d", checkHMAC("123","123",MAC));
}
