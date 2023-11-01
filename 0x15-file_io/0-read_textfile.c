#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints its contents.
 * @filename: The name of the file to read.
 * @letters: The maximum number of letters to read and print.
 *
 * Return: The actual number of letters printed, or 0 if an error.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
FILE *file;
char *buffer;
ssize_t read_count, write_count;

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

read_count = fread(buffer, sizeof(char), letters, file);
if (read_count == -1)
{
fclose(file);
free(buffer);
return (0);
}

buffer[read_count] = '\0';

write_count = fwrite(buffer, sizeof(char), read_count, stdout);
if (write_count != read_count)
{
fclose(file);
free(buffer);
return (0);
}

fclose(file);
free(buffer);

return (read_count);
}

