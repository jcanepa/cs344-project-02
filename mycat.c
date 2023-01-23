#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// did the user specify a (maybe filename) argument in the command?
// Yes argc is 1 or greater, loop through them all
// arg at index i is a valid filename

int main(int argc, const char *argv[])
{
    // read from standard input
    if (argc == 1)
    {
        char buffer[2048];
        while (read(0, buffer, sizeof(buffer)) > 0)
        {
            printf("%s", buffer);
        }
        exit(0);
    }

    // otherwise, process each arg as a filename to cat.
    int file_descriptor;
    char *contents;
    int bytes;

    /* Use syscall to read input file in read-only mode */
    file_descriptor = open(argv[1], O_RDONLY, 0);

    /* Throw error if specified file doesn't exist */
    if (file_descriptor == -1)
    {
        perror("Specified file does not exist");
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