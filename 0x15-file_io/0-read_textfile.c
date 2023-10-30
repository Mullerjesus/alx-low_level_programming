#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - Read and print the contents of a text file.
 * @filename: The name of the text file.
 * @letters: The maximum number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
FILE *file;
char *buffer;
ssize_t bytes_read;

if (filename == NULL)
return (0);

file = fopen(filename, "r");
if (file == NULL)
return (0);

buffer = malloc(sizeof(char) * (letters + 1));
if (buffer == NULL)
{
fclose(file);
return (0);
}

bytes_read = fread(buffer, sizeof(char), letters, file);
if (bytes_read == 0)
{
fclose(file);
free(buffer);
return (0);
}

buffer[bytes_read] = '\0';
printf("%s", buffer);

fclose(file);
free(buffer);

return (bytes_read);
}

