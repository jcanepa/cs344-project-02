#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void read_write_from_file(int file_descriptor)
{
    char *contents;
    int bytes;

    /* Error & return if specified file doesn't exist */
    if (file_descriptor == -1)
    {
        perror("File name specified does not exist");
        exit(1);
    }

    /* Allocate enough space to contain the file contents in memory. */
    contents = (char *)malloc(2048);
    bytes = read(file_descriptor, contents, 2048);

    /* Write the contents to standard output */
    write(1, contents, bytes);
}

int main(int argc, const char *argv[])
{
    // no arguments provided
    if (argc == 1)
    {
        // read from standard input indefinately
        while (1)
        {
            read_write_from_file(0);
        }
        exit(0);
    }

    // Process each supplied arg as a filename
    for (int i = 1; i < argc; i++)
    {
        int file_descriptor = open(argv[i], O_RDONLY, 0);
        read_write_from_file(file_descriptor);
        close(file_descriptor);
    }
}