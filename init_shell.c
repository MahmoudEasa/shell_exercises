#include "main.h"

#define clear() printf("\033[H\033[J")

/**
 * init_shell - Greeting shell during startup
 */

void init_shell(void)
{
	char *username;

	clear();
	printf("\n\n\n******************"
			"************************");
	printf("\n\n\n\t****MY SHELL****");
	printf("\n\n\t-USE AT YOUR OWN RISK-");
	printf("\n\n\n\n*******************"
			"***********************");
	username = _getenv("USERNAME");
	printf("\n\n\nUSER is: @%s", username);
	printf("\n");
	sleep(1);
	clear();
}

