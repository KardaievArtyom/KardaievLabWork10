#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int data_processed;
    char buffer[BUFSIZ + 1];
    int file_descriptor;

    memset(buffer, '\0', sizeof(buffer));
    scanf(argv[1], "%d", &file_descriptor);
    data_processed = read(file_descriptor, buffer, BUFSIZ);
    printf("It is Kardaiev's process child with pid=%d", getpid());
    printf("Kardaiev's process child read %d bytes: %s\n", data_processed, buffer);

    return EXIT_SUCCESS;
}