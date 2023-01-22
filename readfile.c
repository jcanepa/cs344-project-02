#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    /**
     * Exactly one user-provided argument expected.
     * If arg count is off, provide a helpful error.
     */
    if (argc != 2)
    {
        perror("Incorrect number of arguments.");
        exit(0);
    }

    /** Use syscall to read input file in read-only mode */
    int file_descriptor = open(argv[1], O_RDONLY, 0);

    /** Throw error if specified file doesn't exist */
    if (file_descriptor < 0)
    {
        perror("Specified file does not exist");
        exit(0);
    }

    /** Allocate enough space to contain the file contents in memory. */
    char *contents = (char *)malloc(2048);
    int bytes = read(file_descriptor, contents, 2048);

    // write the contents to standard output
    write(1, contents, bytes);
    close(file_descriptor);
}