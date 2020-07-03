#include "HMAC.h"

void  makeHMAC(const char* message, const char* key, unsigned char*  MAC ,int blockSize){
  unsigned char kPrime[blockSize];
  if( strlen(key) > 20)
    {
      RIPEMD160((const unsigned char*) key, (unsigned long ) strlen(key),kPrime); 
    }else
    {
      strcpy(kPrime,(unsigned char*) key);
    }
  char ipad[blockSize];
  char opad[blockSize];  printf("\n");
  for(int i =0;i<strlen(kPrime);i++){
    ipad[i]=0x36 ^ kPrime[i];
    opad[i]=0x5c ^ kPrime[i];
  }
  ipad[strlen(kPrime)]='\0';
  opad[strlen(kPrime)]='\0';
  //concatnate thingsand hash things
  char first [20];
  char catFirst[strlen(ipad)+strlen(message)+1];
  strcpy(catFirst,ipad);
  strcat(catFirst,message);
  catFirst[strlen(ipad)+strlen(message)+1]='\0';
  RIPEMD160((const unsigned char*) catFirst,(unsigned long )strlen(catFirst),first);
  char catSecond[strlen(opad)+strlen(first)];
  strcpy(catSecond,opad);
  strcat(catSecond,first);
  //  catSecond[blockSize+strlen(first)+1]='\0';
  RIPEMD160((const unsigned char*) catSecond, strlen(catSecond)-3,MAC);
  //printf("%s\n",MAC);
  //printf("%d\n",strlen(catSecond));
}

int checkHMAC(char* message,char* key,  char* recevedMAC){
  char MAC[20];
  makeHMAC(message,key,MAC,20);
  MAC[17]='\0';
  printf("%s\n",MAC);
 for(int i = 0; i<strlen(MAC);i++){
   printf("%02x",(unsigned char) MAC[i]);
 }
  return((strcmp(recevedMAC,MAC)));
}
/* int main(){ */
/*  unsigned char MAC[20]; */
/*  makeHMAC("12345","12345",MAC,20); */
/*  MAC[17]='\0'; */
/*  printf("%s\n",MAC); */
/*  printf("%d\n", checkHMAC("12345","12345",MAC)); */
/*    //  printf("%s\n",MAC); */
/*  for(int i = 0; i<strlen(MAC);i++){ */
/*    printf("%02x",(unsigned char) MAC[i]); */
/*  } */
/*  //checkHMAC("123","123",MAC); */
/* } */

