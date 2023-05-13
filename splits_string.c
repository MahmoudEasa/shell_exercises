#include "main.h"

char **words(char *str, char *tok, int *arr_len)
{
	char *token, **arr = NULL;
	int len, i = 0;

	token = _strtok(str, tok);

	arr = malloc(sizeof(char *) * strlen(str));

	while (token)
	{
		*arr_len += 1;
		len = strlen(token);

		arr[i] = malloc(sizeof(char) * (len + 1));
		if (!arr[i])
			return (NULL);

		arr[i] = token;
		i++;
		token = _strtok(NULL, tok);
	}

	free(token);
	return (arr);
}

char *_strtok(char *str, char *tok)
{
	static int len = 0;
	static char *token, *ptr;

	if (str)
	{
		len = strlen(str);
		token = malloc(sizeof(char) * (len + 1));
		if (!token)
			return (NULL);

		strcpy(token, str);
		ptr = token;
		len = 0;
		return (allocate(token, *tok, &len));
	}

	if (!str && token && *token)
	{
		token += len;
		len = 0;
		return (allocate(token, *tok, &len));
	}

	if (*token == '\0')
	{
		free(ptr);
		token = NULL;
	}

	return (token);
}

char *allocate(char *token, char tok, int *tok_len)
{
	char *ptr, *tok_help = token;
	int i, len = 0;

	while (*token != tok)
	{
		len++;
		*tok_len += 1;
		token++;
		if (*token == '\0')
			break;
	}

	while (*token == tok)
	{
		*tok_len += 1;
		token++;
	}

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);

	for (i = 0; i < len; i++)
		ptr[i] = *tok_help++;

	return (ptr);
}
