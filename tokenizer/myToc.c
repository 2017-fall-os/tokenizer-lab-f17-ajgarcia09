#include <stdio.h>
#include <sys/types.h>//for read
#include <unistd.h>//for read
#include <sys/stat.h>//for read
#include <fcntl.h> //for read
#include <stdlib.h>
#include <assert.h>
#include "myToc.h"

#define BUFLEN 1024    
    

int countWords(char * str, char delim){
  int wordCount = 0;
  while(*str){
    while(*str == delim){
      str++;
    }
    if(*str != 0){
      wordCount++;
    }
    while(*str && (*str != delim)){
      str++;
    }
  }
  printf("wordCount = %d\n",wordCount);
  return wordCount;
 }
/*	
int countWords(char * str, int numBytesRead, char delim){
  printf("entered countWords\n");
  int wordCount = 0;  
  assert(numBytesRead >0);
  int i = 0;
  
  for(; str[i] != 0 ; i++){
    if(str[i] == delim){
       continue;
    }
    if(str[i]){
      wordCount++;
    }
    if(str[i] && str[i] != delim){
      continue;
    }
  }
      
   printf("numWords:%d\n",wordCount);
   return wordCount;
   }*/

char * copyToken(char *str, int tokLength){
printf("entered copyToken");
  char *strCopy = (char *)malloc(tokLength+1);
  /*copy each character from the current
    token in str into strCopy*/
  for(int i = 0; *str; i++){
    strCopy[i] = str[i];
  }
  strCopy[tokLength] = 0;
  return strCopy;
  
}


 
char ** allocateTokens(char ** tokenVec, char *str, char delim){

  int tokLength =0;
  int tokNum=0;
  while(*str){
    printf("entered toklength for loop\n");
    if(*str != delim && *str!= 0){
      tokLength++;
      printf("tokLength: %c%d\n",*str, tokLength);
      str++;
    }
    else{
    printf("entered else\n");  
    printf("tokLength: %d\n",tokLength);
    printf("tokNUm: %d\n", tokNum);
    //copy the current token to this array, add a 0 char terminator
    tokenVec[tokNum] = copyToken(str,tokLength);
    printf("malloc-ed");    
    tokNum++; //go to the next token
    tokLength = 0; //reset token length
    str++; //go to the next index of str
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
     free(tokenVec[i]);
    }
  free(tokenVec);
}


char ** mytoc(char *str, char delim){

  write(1,"$ ",2);
 int numBytesRead = read(0, str, BUFLEN);
 str[numBytesRead-1] = 0; //remove '\n' from end of str
 printf("str[numBytesRead-1]: %c\n", str[numBytesRead-1]);
 printf("Sentence entered: %s\n", str);
 printf("numBytes entered is:%d\n", numBytesRead);
 int wordCount = countWords(str, delim);
 printf("wordCount is:%d\n",wordCount);

 char** tokenVec = (char **)calloc(wordCount+1,sizeof(char *));

 tokenVec = allocateTokens(tokenVec, str,delim);
 tokenVec[wordCount] = (char *)0;
 //print contents of tokenVec to stdout
  // and free the memory
 printTokenVec(tokenVec, wordCount);
 return tokenVec;

}
