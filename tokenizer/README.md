#Tokenizer -ajgarcia09
# source code by Ana J. Garcia

This directory contains:
*code that takes an input string and breaks it up into tokens and stores them in a character array
*a demo program that uses this code

The demo program reads lines from stdin -which are input by the user on the keyboard. Each line is broken up into "tokens" based on the default delimiter, the blank space ' '. These tokens are stored in a character array and are printed on stdout, one token per line.

This directory contains:
    myToc.h: header file with function instantiations
    myToc.c: implementation of funcions from myToc.h
    test.c: a demo program that implements the tokenizer

To compile:

~~~
$ make
~~~

To test it:
~~~
$ make demo
~~~

To delete binaries:
~~~
$ make clean
~~~

For the completion of this assignment, I collaborated in a group made up of the following members:

*Ricardo Alvarez
*Hector Cervantes
*Abner Palomino
*Kristian Villanueva

We discussed the ideal algorithm to follow, and helped each other debugging some issues. We also used K & R's "The C Programming Language" handbook as a reference for using functions including malloc and calloc.


