#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
/**
 *  Check if the correct number of command-line arguments is provided
 */
if (argc != 2)
{
printf("Usage: %s <password>\n", argv[0]);
return 1;
}

/*Define the correct password*/
const char *correctPassword = "password123";

/* Check if the provided password matches the correct password*/

if (strcmp(argv[1], correctPassword) == 0)
{
printf("Access granted!\n");}
else
{
printf("Access denied!\n");
}

return 0;
}

