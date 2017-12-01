#include <stdio.h>
#include <sys/types.h>//for read
#include <unistd.h>//for read
#include <sys/stat.h>//for read
#include <fcntl.h> //for read
#include "myToc.h"

#define BUFLEN 1024

int main(){
  for(;;){
  char buf[BUFLEN];	     
  char delim = '|';
  write(1,"$ ",2);
  int numBytesRead = read(0, buf, BUFLEN);
  buf[numBytesRead-1] = '\0';
  if(compStrings(buf, "exit") == 1){
    break;
  }
  char ** mytoken =  mytoc(buf, delim);
  }
  return 0;
}
