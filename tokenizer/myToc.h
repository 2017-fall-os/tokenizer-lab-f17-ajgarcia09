#ifndef MyTocIncluded
#define MyTocIncluded

int countWords(char * str, char delim);

//int countWords(char *str, int numBytesRead, char delim);

char ** mytoc(char *str, char delim);

char ** allocateTokens(char ** tokenVec, char *str,char delim);

void printTokenVec(char ** tokenVec, int wordCount);

int lengthOfTokenArray(char * str);

#endif
