#include "textIn.h"
int Chaffing(FILE *in, FILE *out, const char*key){
  char buff = fgetc(in);
  while((buff!= EOF)){
      if(random_uint(10)%3==0){
	char fake = (char) random_uint(94)+32;
	fputc(fake,out);
	fputc(',',out);
	char newfake = (char) random_uint(94)+32;
	while (newfake == fake){
	  newfake = (char) random_uint(94)+32;
	}
	 unsigned char MAC[20];
	 makeHMAC(&fake,key,MAC,20);
	MAC[17]='\0';
        for(size_t i=0; i< 17; i++ ) fprintf(out,"%02x",MAC[i]);	
      }else{
	fputc(buff,out);
	unsigned char MAC[20];
	makeHMAC(&buff,key,MAC,20);
	MAC[17]='\0';
	fputc(',',out);
	for(size_t i=0; i<17; i++ ) fprintf(out,"%02x",MAC[i]);
	//fputs((int*)MAC,out);
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
int windowing(FILE *in, FILE *out,const char* key){
  char buff[20];
  char letter;
    while(letter!=EOF){
      fscanf(in,"%c",&letter);
      for(int i=0; i<20;i++){
	fscanf(in,"%x",&buff[i]);
	if(buff[i]==EOF)
	  return 0;
	printf("%s\n",buff);
	
      }
      if(!checkHMAC(letter,key,buff)){
	printf("here");
	fputc(letter,out);
      }
    }
}


int main(int argc, char *argv[]){
  if(argc<2){
    printf("usage file in, file out, Key, chaffing(0) or windowing (1)");
    return -1;
  }
  FILE* in=fopen(argv[1],"r+");
  FILE*  out=fopen(argv[2],"w+");
  if(in == NULL || out == NULL ){
    printf("error while opeing or creating files");
  }
  if(argv[4][0]=='0'){
    Chaffing(in,out,argv[3]);
    return 1;
  }
  else if(argv[4][0]=='1') {
    windowing(in,out,argv[3]);
    return 1;
  }
  fclose(in);
  fclose(out);
  return 0;
}
