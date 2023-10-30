#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* append_text_to_file - Appends text at the end of a file.
* @filename: The name of the file.
* @text_content: The NULL terminated string to add at the end of the file.
*
* Return: 1 on success, -1 on failure.
*-1 if filename is NULL or if you don't have the required permissions to write.
* If text_content is NULL, the file remains unchanged.
* If the file does not exist, it will not be created.
*/

int append_text_to_file(const char *filename, char *text_content)
{
FILE *file;

if (filename == NULL)
return (-1);

file = fopen(filename, "a");
if (file == NULL)
return (-1);

if (text_content != NULL)
{
size_t len = strlen(text_content);
fwrite(text_content, sizeof(char), len, file);
}

fclose(file);
return (1);
}
