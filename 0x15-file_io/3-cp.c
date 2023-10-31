#include "main.h"
#include <stdio.h>

/**
* main - check the code.
* @argc: number of arguments.
* @argv: arguments vector.
* Return: Always 0.
*/

int main(int argc, char *argv[])
{
int file_from, file_to, err_close;
ssize_t nchars, nwr;
char buf[1024];

if (argc != 3)
{
dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
return (97);
}

file_from = open(argv[1], O_RDONLY);
file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);

nchars = 1024;
while (nchars == 1024)
{
nchars = read(file_from, buf, 1024);
if (nchars == -1)

nwr = write(file_to, buf, nchars);
if (nwr == -1)
}

err_close = close(file_from);
if (err_close == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
return (100);
}

err_close = close(file_to);
if (err_close == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
return (100);
}
return (0);
}
