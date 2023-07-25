#include <shell.h>

ssize_t _getline()
{
/*** Buffer to read the command line into ***/
	char cmdline[1024] = {'\0'};

/*** Stores the commandlines ***/
	static char *cmdlines[64] = {NULL}; 

	ssize_t len; 
	char *file;
	int a = 0;

/*** checking if there no pending commandfile to execute. we only want read 
 * file if there is no pending command ***/
	if (cmdfiles[0] == NULL) 
	{
		/*** No pending command, we need to read ***/
		len = read(STDIN_FILENO, cmdfile, 1024);
		/*** check if EOF was read ***/
		if (len == 0) {	
		/*** free any necessary data and exit since this will only occur in 
		 * non-interactive mode ***/
		exit(errno);
		}
		/*** Get all commandfiles fron the command ***/
		file = 
