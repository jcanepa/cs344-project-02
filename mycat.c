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

    /* Close the file */
    close(file_descriptor);
}

int main(int argc, const char *argv[])
{
    // no arguments provided
    if (argc == 1)
    {
        // read from standard input
        char buffer[2048] = {'\0'};

        while (1)
        {
            int count = read(0, buffer, 2048);
            write(1, buffer, count);
        }
        exit(0);
    }

    // Process each supplied arg as a filename
    for (int i = 1; i < argc; i++)
    {

        int file_descriptor;

        /* Read input file in read-only mode */
        file_descriptor = open(argv[i], O_RDONLY, 0);
        read_write_from_file(file_descriptor);
    }
}