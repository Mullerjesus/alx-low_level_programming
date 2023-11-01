#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
* check_elf - Checks if the file is an ELF file.
* @e_ident: A pointer to an array containing the ELF class.
*/
void check_elf(unsigned char **e_ident)
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
* print_osabi - Prints the OS/ABI of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:                           ");
switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("UNIX - ARM architecture\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone (embedded) application\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
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

