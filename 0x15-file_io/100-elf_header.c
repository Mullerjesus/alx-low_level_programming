#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
* print_error_and_exit - Print an error message and exit the program.
* @error_message: The error message to be printed.
* This function prints the specified error message to the standard error stream
* and exits the program with a status code of 98.
*/
void print_error_and_exit(const char *error_message)
{
fprintf(stderr, "%s\n", error_message);
exit(98);
}
/**
* print_elf_header - Print the information contained in the ELF header.
* @header: A pointer to the ELF header structure.*
* This function prints the information contained in the specified ELF header
* structure to the standard output stream.
*/
void print_elf_header(const Elf64_Ehdr *header)
{
printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
printf("%02x ", header->e_ident[i]);
printf("\n");
printf("  Class:                             ");
switch (header->e_ident[EI_CLASS])
{
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("Invalid\n");
break;
}
printf("  Data:                              ");
switch (header->e_ident[EI_DATA])
{
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("Invalid\n");
break;
}
printf("  Version:                 %d (current)\n", header->e_version);
printf("  OS/ABI:          %s\n", get_os_abi_name(header->e_ident[EI_OSABI]));
printf("  ABI Version:             %d\n", header->e_ident[EI_ABIVERSION]);
printf("  Type:                    %s\n", get_file_type_name(header->e_type));
printf("  Entry point address:     0x%lx\n", header->e_entry);
}

