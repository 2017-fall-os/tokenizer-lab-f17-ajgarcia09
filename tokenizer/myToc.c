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
  int numWords = 0;  
  assert(numBytesRead >0);
  int i = 0;
  
  //don't count initial blank spaces
  while(buf[i] == delim){
    printf("entered while loop\n");
    i++;
  }

for(; buf[i] != 0 ; i++){
  if(buf[i] == delim || buf[i] == '\n'){
    numWords++;
    printf("numWords:%d\n",numWords);
  }
 }
printf("leaving countWords\n");
  return numWords;
}

char * copyToken(char *str){
  int length;
  //compute the length of str
  for(length =0; str[length]; length++)
    ;
  char *strCopy = (char *)malloc(length+1);

  //copy each character from str into strCopy;
  for(length =0; str[length]; length++){
    strCopy[length] = str[length];
  }
  strCopy[length] = 0;
  return strCopy;
  
}

char ** allocateTokens(char ** tokenVec, char *str, char delim){
  int tokLength =0;
  int tokNum=0;
  for(int i =0; str[i]!=0; i++){
    printf("entered toklength for loop\n");
    if(str[i] != delim && str[i] != '\n'){
      tokLength++;
      printf("tokLength: %d\n", tokLength);
    }
    else{
      printf("entered else\n");  
    printf("tokLength: %d\n",tokLength);
    tokenVec[tokNum] = (char *)malloc(tokLength +1);
    //copy the current token to this array, add a 0 char terminator
    tokenVec[tokNum] = copyToken(str);
    tokNum++; //go to the next token
    tokLength = 0; //reset token length
  }
  }
 
  return tokenVec;
}

void printTokenVec(char ** tokenVec, int wordCount){
  printf("entered printTokenVec function\n");
  printf("wordCount: %d\n ", wordCount);
  printf("tokenVec[0]: %s\n",tokenVec[0]);
  printf("tokenVec[1]: %s\n",tokenVec[1]);
for(int i = 0; i < wordCount; i++){
  printf("i = %d\n",i);
    printf("size of index: %d\n", sizeof(tokenVec[i])-1);
     write(1,tokenVec[i],sizeof(tokenVec[i])-1);
     //free(tokenVec[i]);
    }
  //free(tokenVec);
}


    //void print2(char** tokenVec){

char ** mytoc(char *str, char delim){
  
 int numBytesRead;
 write(1,"$ ",2);
 numBytesRead = read(0, str, BUFLEN);
 printf("Sentence entered!\n");
 printf("numBytes entered is:%d\n", numBytesRead);
 int wordCount = countWords(str, numBytesRead, delim);
 printf("wordCount is:%d\n",wordCount);

 char** tokenVec = (char **)calloc(wordCount+1,sizeof(char *));

 tokenVec = allocateTokens(tokenVec, str,delim);
 tokenVec[wordCount] = (char *)0;
 /*print contents of tokenVec to stdout
   and free the memory*/
 printTokenVec(tokenVec, wordCount);
 
 return tokenVec;

}
