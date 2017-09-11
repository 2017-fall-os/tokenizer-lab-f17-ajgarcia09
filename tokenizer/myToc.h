#ifndef MyTocIncluded
#define MyTocIncluded

int countWords(char * str, char delim);

//int countWords(char *str, int numBytesRead, char delim);

char ** mytoc(char *str, char delim);

char ** allocateTokens(char ** tokenVec, char *str,char delim, int wordCount);

char * copyToken(char *str, int tokLength);

void printTokenVec(char ** tokenVec, int wordCount);


#endif
