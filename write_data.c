#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int data_processed;
    int file_pipes[2];
    const char message[] = "Kardaiev's Laborathory Work.";
    char buffer[BUFSIZ + 1];
    pid_t pid;
    char *program_args[] = {"read_data", buffer, NULL};

    memset(buffer, '\0', sizeof(buffer));
    if (pipe(file_pipes) == 0)
    {
        pid = fork();
        if (pid == 0)
        {
            sprintf(buffer, "%d", file_pipes[0]);
            execv("./read_data", program_args);
        }
        else
        {
            data_processed = write(file_pipes[1], message, strlen(message));
            printf("It is Kardaiev's process parent with pid=%d. ", getpid());
            printf("Parent wrote %d bytes of message.\n", data_processed);
            sleep(1);
        }
        return EXIT_SUCCESS;
    }
}