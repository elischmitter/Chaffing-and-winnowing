#include "textIn.h"
int Chaffing(FILE *in, FILE *out, const char*key){
  char buff = fgetc(in);
  while((buff!= EOF)){
      if(random_uint(10)%3==0){
	char fake = (char) random_uint(195)+32;
	fputc(fake,out);
	fputc(',',out);
	unsigned char MAC[20];
	makeHMAC(&fake,key,MAC,20);
	MAC[17]='\0';
	fputs(MAC,out);	
      }else{
	fputc(buff,out);
	unsigned char MAC[20];
	makeHMAC(&buff,key,MAC,20);
	MAC[17]='\0';
	fputc(',',out);
	fputs(MAC,out);
	buff = fgetc(in);
      }
      fputc('\n',out);
  }
  return 1;
   
}
unsigned int random_uint(unsigned int limit) {
    union {
      unsigned int i;
      unsigned char c[sizeof(unsigned int)];
    } u;
    
    do {
      if (!RAND_bytes(u.c, sizeof(u.c))) {
	fprintf(stderr, "Can't get random bytes!\n");
	exit(1);
      }
    } while (u.i < (-limit % limit)); /* u.i < (2**size % limit) */
    return u.i % limit;
}


int main(int argc, char *argv[]){
  if(argc<2){
    printf("usage file in, file out, Key");
    return -1;
  }
  FILE* in=fopen(argv[1],"r+");
  FILE*  out=fopen(argv[2],"w+");
  if(in == NULL || out == NULL ){
    printf("error while opeing or creating files");
  }
  Chaffing(in,out,argv[3]);
  return 1;
}
