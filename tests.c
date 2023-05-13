#include "main.h"

int main(int argc, char **argv)
{
        char **arr, *getenv;
        int len = 0, i;
	(void)arr;
	(void)getenv;
	(void)len;
	(void)i;
	(void)argc;
	(void)argv;

	if (argc != 2)
	{
		printf("Usage: %s <str>\n", argv[0]);
		return (0);
	}

/*        if (argc != 3)
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
        free(arr);*/

	getenv = _getenv(argv[1]);

	printf("Env Value: %s\n", getenv);
        return (0);
}

