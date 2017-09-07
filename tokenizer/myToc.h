#ifndef MyTocIncluded
#define MyTocIncluded


int countWords(char *buf, int numBytesRead, char delim);

char ** mytoc(char *str, char delim);

char ** allocateTokens(char ** tokenVec, char *str,char delim);

char * copyToken(char *str);

void printTokenVec(char ** tokenVec, int wordCount);


#endif
