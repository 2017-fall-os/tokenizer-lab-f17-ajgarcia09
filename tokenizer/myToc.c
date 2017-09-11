#include <stdio.h>
#include <sys/types.h>//for read
#include <unistd.h>//for read
#include <sys/stat.h>//for read
#include <fcntl.h> //for read
#include <stdlib.h>
#include <assert.h>
#include "myToc.h"

#define BUFLEN 1024
int indexOfCopy = 0;
    

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

char * copyToken(char *str, int tokLength){
 //printf("entered copyToken\n");
  /*copy each character from the current
    token in str into strCopy*/
  char * strCopy = (char *)malloc(tokLength +1);
  printf("str is: %s\n", str);
  for(int i = 0; i< tokLength; i++){
    strCopy[i] = str[i];
    /* printf("str[i] = %c\n", str[i]);
       printf("strCopy[i] = %c\n", strCopy[i]);*/
  }
  strCopy[tokLength] = 0; //terminate copy
  //printf("strCopy[tokLength] = %s\n", strCopy[tokLength]);
  printf("strCopy is: %s\n", strCopy);
return strCopy;
  
}
 
char ** allocateTokens(char ** tokenVec, char *str, char delim){

  int tokLength =0;
  int tokNum=0;
  char * temp;
  while(*str){
    if(*str != delim){
      tokLength++;
      str++;
    }
    //found a delimiter
    else{
    temp = str-tokLength;    
    //printf("entered else, tokLength = %d\n", tokLength);
    //storage for current token    
    tokenVec[tokNum] = (char *)malloc(tokLength+1);
    //printf("malloced tokenVec[tokNum]!\n");
    //printf("tokNum = %d\n", tokNum);
    //and its 0 char terminator
    tokenVec[tokLength] = 0;
    tokenVec[tokNum] = copyToken(temp,tokLength);
    printf("tokenVec[tokNum] = %s\n",tokenVec[tokNum]);
    printf("tokenVec[tokLength] = %s\n",tokenVec[tokLength]);
    tokNum++; //go to the next token
    tokLength = 0; //reset token length
    str++; //go to the next index
    
    }
  }
  return tokenVec;
}

void printTokenVec(char ** tokenVec, int wordCount){
  for(int i = 0; i < wordCount; i++){
    //printf("i = %d\n",i);
    //printf("size of index: %d\n", sizeof(tokenVec[i])-1);
     write(1,tokenVec[i],sizeof(tokenVec[i]));
     //free(tokenVec[i]);
    }
//free(tokenVec);
}


char ** mytoc(char *str, char delim){

  //write(1,"$ ",2);
 //int numBytesRead = read(0, str, BUFLEN);
 printf("Sentence entered: %s\n", str);
 //printf("numBytes entered is:%d\n", numBytesRead);

 int wordCount = countWords(str, delim);
 
 char** tokenVec = (char **)calloc(wordCount+1,sizeof(char *));
 tokenVec[wordCount] = (char *)0;//zero pointer terminator
 printf("malloced tokenVec!\n");
 
 tokenVec = allocateTokens(tokenVec,str,delim);

return tokenVec;

}
