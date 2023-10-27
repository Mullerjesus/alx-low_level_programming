#include <stdio.h>
/**
 * get_endianness - A function that checks endianness
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
unsigned int num = 1;
char *endian = (char *)&num;

if (*endian == 1)
return (1);  /* Little Endian */
else
return (0);  /* Big Endian */
}

int main(void)
{
int n;

n = get_endianness();
if (n != 0)
{
printf("Little Endian\n");
}
else
{
printf("Big Endian\n");
}
return (0);
}

