/*
3. Create a multi-ﬁle project (main.c, circle.c/.h, square.c/.h, rectangle.c/.h). Compile the program using "gcc" and execute it. No fork(), exec() expected
here.
Compilation commands:
gcc -c circle.c
gcc -c square.c
gcc -c rectangle.c
gcc -c main.c
Linking command:
gcc -o program.out circle.o square.o rectangle.o main.o
Execute command:
./program.out

*/


#include<stdio.h>
#include "circle.h"
#include"square.h"
#include"rectangle.h"
int main()
{
    circle();
	square();
	rectangle();
	return 0;
}
