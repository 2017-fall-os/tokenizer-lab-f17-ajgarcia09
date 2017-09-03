#include <stdio.h>
#include <assert.h>
#include "myToc.h"

int countWords(char * buf, int numBytesRead){
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
}
