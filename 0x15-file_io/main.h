#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <elf.h>
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void check_arguments(int argc);
void open_files(int *file_from, int *file_to, char *argv[]);
void copy_content(int file_from, int file_to, char *argv[]);
void check_arguments(int argc);
void open_file(int *file, char *argv[]);
void read_elf_header(int file, Elf64_Ehdr *ehdr);
void check_elf_header(Elf64_Ehdr *ehdr);
void print_magic(Elf64_Ehdr *ehdr);
char *get_class(Elf64_Ehdr *ehdr);
void print_class(Elf64_Ehdr *ehdr);
char *get_data(Elf64_Ehdr *ehdr);
void print_data(Elf64_Ehdr *ehdr);
char *get_version(Elf64_Ehdr *ehdr);
void print_version(Elf64_Ehdr *ehdr);
char *get_osabi(Elf64_Ehdr *ehdr);
void print_osabi(Elf64_Ehdr *ehdr);
void print_abiversion(Elf64_Ehdr *ehdr);
char *get_type(Elf64_Ehdr *ehdr);
void print_type(Elf64_Ehdr *ehdr);
void print_entry(Elf64_Ehdr *ehdr);
void close_file(int file);


#endif
