#include <stdio.h>
#include <sys/types.h>//for read
#include <unistd.h>//for read
#include <sys/stat.h>//for read
#include <fcntl.h> //for read
#include "myToc.h"

#define BUFLEN 1024

void callMyToc(){
  char buf[BUFLEN] = "anita lava la tina";	     
  char delim = ' ';
  char ** mytoken =  mytoc(buf, delim);
  int wordsInBuf = countWords(buf, delim);
  /*printf("Printing tokenVec:\n");
    printTokenVec(mytoken,wordsInBuf);*/
}
  

int main(){
  // for(;;){
  callMyToc();
  // }
  return 0;
}
