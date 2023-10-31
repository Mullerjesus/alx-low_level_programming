#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
int fd_from, fd_to, ret;
char buf[BUF_SIZE];
ssize_t num_read, num_written;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}

while ((num_read = read(fd_from, buf, BUF_SIZE)) > 0)
{
num_written = write(fd_to, buf, num_read);
if (num_written != num_read)
{
dprintf(STDERR_FILENO, "Error: Write to %s failed\n", argv[2]);
exit(99);
}
}

if (num_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

ret = close(fd_from);
if (ret == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
exit(100);
}

ret = close(fd_to);
if (ret == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}

exit(0);
}
