#include <stdio.h>
#include <sys/types.h>//for read
#include <unistd.h>//for read
#include <sys/stat.h>//for read
#include <fcntl.h> //for read
#include <stdlib.h>
#include <assert.h>
#include "myToc.h"

#define BUFLEN 1024

int countWords(char * buf, int numBytesRead, char delim){
  printf("entered countWords\n");
  if(numBytesRead == 0){
    printf("no bytes read!!!!!\n");
  }
  int numWords = 0;
  int i = 0;
  
  //don't count initial blank spaces
  while(buf[i] == ' '){
    printf("entered while loop\n");
    i++;
  }

for( ; buf[i] != 0 ; i++){
    printf("entered for loop\n");
    if(buf[i] == delim || buf[i] == '\n'){
      printf("entered if statement\n");
      numWords++;
      printf("numWords:%d\n",numWords);
    }
  }
  printf("leaving countWords\n");
  return numWords;
}

char ** allocateTokens(char ** tokenVec, char *str){


}

char ** mytoc(char *str, char delim){
  
 int numBytesRead;
 write(1,"$ ",2);
 numBytesRead = read(0, &str, BUFLEN);
 printf("Sentence entered!\n");
 printf("numBytes entered is:%d\n", numBytesRead);
 int wordCount = countWords(str, numBytesRead, delim);
 printf("wordCount is:%d\n",wordCount);

 char** tokenVec = (char **)calloc(wordCount+1,sizeof(char *));

 //tokenVec = allocateTokens(tokenVec, str);

 return tokenVec;

}
