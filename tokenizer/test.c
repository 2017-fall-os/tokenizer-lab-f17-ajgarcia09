#include <stdio.h>
#include <sys/types.h>//for read
#include <unistd.h>//for read
#include <sys/stat.h>//for read
#include <fcntl.h> //for read
#include "myToc.h"

/*void readInput(){
  int numBytesRead;
  int bufLen = 1024;
  char buf[bufLen];
  printf("Enter sentence:\n");
  numBytesRead = read(0, &buf, bufLen);
  printf("Sentence entered!\n");
  printf("numBytes entered is:%d\n", numBytesRead);
  int wordCount = countWords(buf, numBytesRead, ' ');
  printf("wordCount is:%d\n",wordCount);

  }*/
void promptUser(){
  int numBytesRead;
  int bufLen = 1024;
  char buf[bufLen];

      printf("Enter Sentence:\n");
      numBytesRead = read(0, &buf, bufLen);
      printf("Sentence entered!\n");
      printf("numBytes entered is:%d\n", numBytesRead);
      int wordCount = countWords(buf, numBytesRead, ' ');
      printf("wordCount is:%d\n",wordCount);

  
}

int main(){
  promptUser();
  return 0;
}
