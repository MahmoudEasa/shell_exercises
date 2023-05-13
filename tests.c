#include "main.h"

int main(int argc, char **argv)
{
        char **arr;
        int len = 0, i;

        if (argc != 3)
        {
                printf("Usage: <str> <token>\n");
                return (0);
        }

        arr = words(argv[1], argv[2], &len);

        for (i = 0; i < len; i++)
        {
                printf("%s\n", arr[i]);
                free(arr[i]);
        }
        free(arr);
        return (0);
}

