#include <stdio.h>
#include <sys/types.h>//for read
#include <unistd.h>//for read
#include <sys/stat.h>//for read
#include <fcntl.h> //for read
#include "myToc.h"

#define BUFLEN 1024

void readInput(){
  int numBytesRead;
  char buf[BUFLEN];
  char delim = ' ';
  write(1,"$ ",2);
  numBytesRead = read(0, &buf, BUFLEN);
  printf("Sentence entered!\n");
  printf("numBytes entered is:%d\n", numBytesRead);
  int wordCount = countWords(buf, numBytesRead, delim);
  printf("wordCount is:%d\n",wordCount);

  }

void callMyToc(){
int bufLen = 1024;
  char buf[BUFLEN];
  char delim = ' ';
  char ** mytoken =  mytoc(buf, delim);
}
  

int main(){

  readInput();
  //callMyToc();
  
  return 0;
}
