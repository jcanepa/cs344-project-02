#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void read_write_from_file(const char *filename)
{
    int file_descriptor;
    char *contents;
    int bytes;

    /* Read input file in read-only mode */
    file_descriptor = open(filename, O_RDONLY, 0);

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

        while (read(0, buffer, 2048) > 0)
        {
            write(1, buffer, 2048);
        }
        exit(0);
    }

    // Process each supplied arg as a filename
    for (int i = 1; i < argc; i++)
    {
        read_write_from_file(argv[i]);
    }
}