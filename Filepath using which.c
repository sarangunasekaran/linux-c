#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
    char bufferid[PATH_MAX];
    char *command;
    int lenof;
    char defaultkey[] = "which ";
    char *condition_match;
    int bytes_read, j = 0;
    size_t size = 10;
    printf("Enter filename:\n");
    command = (char *)malloc(size);
    bytes_read = getline(&command, &size, stdin);
    condition_match = strstr(command, defaultkey);
    if (!condition_match)
    {
        printf("bash: Command: not found\n");
    }
    else
    {
        for (int i = 0; command[i]; i++)
        {

            if (command[i] == defaultkey[j])
            {
                j++;
            }
            else if (command[i] == defaultkey[0])
                j = 1;
            else
                j = 0;
            if (defaultkey[j] == '\0')
            {
                i = i + 1 - j;
                for (int k = i; command[k] = command[k + j]; k++)
                    ;
                j = 0;
            }
        }
        lenof = strlen(command);
        char direc[lenof];
        for (int ab = 0; ab < lenof - 1; ab++)
        {
            direc[ab] = command[ab];
        }
        char *directory = realpath(direc, bufferid);
        if (directory)
        {
            printf("%s\n", bufferid);
        }
        else
        {
            perror("realpath");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}