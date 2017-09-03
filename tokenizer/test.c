#include <stdio.h>
#include <sys/types.h>//for read
#include <unistd.h>//for read
#include <sys/stat.h>//for read
#include <fcntl.h> //for read
#include "myToc.h"

/*int countWords(char * buf, int numBytesRead){
  int numWords = 0;
  char lastChar;
  char *indexAtBuf, *pBufLImit;
  pBufLImit = buf + numBytesRead;

  for(indexAtBuf = buf; indexAtBuf != pBufLImit; indexAtBuf++){
    lastChar = *indexAtBuf;
    if(lastChar == ' ' || lastChar == '\n'){
      numWords++;
    }
  }
  return numWords;
  }*/

int main(){
  int numBytesRead;
  int bufLen = 1024;
  char buf[bufLen];
  printf("Enter sentence:\n");
  numBytesRead = read(0, &buf, bufLen);
  printf("Sentence entered!\n");
  printf("numBytes entered is:%d\n", numBytesRead);
  int wordCount = countWords(buf, numBytesRead);
  printf("wordCount is:%d\n",wordCount);

  return 0;
}
