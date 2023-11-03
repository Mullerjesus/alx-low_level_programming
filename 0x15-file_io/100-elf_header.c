#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
/**
* check_elf - Checks if the file is an ELF file.
* @e_ident: A pointer to an array containing the ELF class.
*/
void check_elf(unsigned char *e_ident)
{
if (e_ident[EI_MAG0] != ELFMAG0 ||
e_ident[EI_MAG1] != ELFMAG1 ||
e_ident[EI_MAG2] != ELFMAG2 ||
e_ident[EI_MAG3] != ELFMAG3)
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
/**
* print_data - Prints the data encoding of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_data(unsigned char *e_ident)
{
printf("  Data:                             ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("Unknown data format\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_DATA]);
}
}
/**
* print_version - Prints the version of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_version(unsigned char *e_ident)
{
printf("  Version:                          ");
if (e_ident[EI_VERSION] == EV_CURRENT)
printf("%d (current)\n", e_ident[EI_VERSION]);
else
printf("%d\n", e_ident[EI_VERSION]);
}

/**
* print_type - Prints the type of an ELF header.
* @e_type: The type of the ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_type(uint16_t e_type, unsigned char *e_ident)
{
printf("  Type:                             ");
if (e_ident[EI_CLASS] == ELFCLASS32)
{
switch (e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", e_type);
}
}
}
/**
* main - Entry point.
* @argc: The number of arguments passed to the program.
* @argv: An array of pointers to the arguments.
* Return: 0 on success, 98 on failure.
*/
int main(int argc, char **argv)
{
int fd;
Elf32_Ehdr elf_header;
unsigned char *e_ident = elf_header.e_ident;
if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s <elf_filename>\n", argv[0]);
exit(98);
}
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
exit(98);
}
if (read(fd, &elf_header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
{
dprintf(STDERR_FILENO, "Error: Cannot read ELF header\n");
exit(98);
}
check_elf(e_ident);
printf("ELF Header:\n");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf(" < vnknown : %x > \n", e_ident[EI_CLASS]);
}

return (0);
}
