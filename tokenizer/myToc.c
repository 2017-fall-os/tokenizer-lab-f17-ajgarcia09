#include <stdio.h>
#include <assert.h>
#include "myToc.h"

int countWords(char * buf, int numBytesRead, char delim){
  int numWords = 0;
  char lastChar;
  char *indexAtBuf, *pBufLImit;
  pBufLImit = buf + numBytesRead;

  for(indexAtBuf = buf; indexAtBuf != pBufLImit; indexAtBuf++){
    lastChar = *indexAtBuf;
    if(lastChar == delim || lastChar == '\n'){
      numWords++;
    }
  }
  return numWords;
}

char ** mytoc(char *str, char delim){


}
