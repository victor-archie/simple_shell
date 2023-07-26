#include <shell.h>

ssize_t _getline()
{
	char cmdline[1024] = {'\0'};

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
		file = strtok_r(cmdfile, "\n");
	}

	cur_cmdfile - cmdfiles[0];
	a = 0;

	while (cmdfiles[a] != NULL)
		cmdfiles[a] = cmdfiles[a + 1];

	if (cur_cmdfile)
		return strlen(cur_cmdfile);
	return (0);
}
