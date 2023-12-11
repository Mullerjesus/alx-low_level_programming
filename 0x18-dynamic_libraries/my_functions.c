#include "main.h"
#include <string.h>

/**
* Calculates the length of a string.
* 
* @param s Pointer to the null-terminated byte string to be examined
* @return The length of the string
*/
int _strlen(char *s)
{
int len = 0;
while (*s != '\0')
{
len++;
s++;
}
return (len);
}

/**
* Adds two integers.
* 
* @param a The first integer
* @param b The second integer
* @return The sum of the two integers
*/
int add(int a, int b)
{
return (a + b);
}
