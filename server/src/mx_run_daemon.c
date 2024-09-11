#include "server.h"
#include "libmx.h"
#include "signal.h"
#include <sys/types.h>
#include <sys/stat.h>

void mx_run_daemon() {
	pid_t pid;

	pid = fork();
	if (pid < 0) exit(EXIT_FAILURE);
	if (pid > 0) exit(EXIT_SUCCESS);

	// run a program in a new session
	if (setsid() < 0) exit(EXIT_FAILURE);

	// ignore signals from the control terminal
	signal(SIGCHLD, SIG_IGN);
	signal(SIGHUP, SIG_IGN);

	// second fork to be sure that daemon can not capture the terminal
	pid = fork();
	if (pid < 0) exit(EXIT_FAILURE);

	// print process id of the server
    if (pid > 0) {
		mx_printint((int)pid);
		mx_printchar('\n');
		exit(EXIT_SUCCESS);
	}

	// set file mode creation mask
	umask(0);

	// close file descriptors
	close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

	return;
}

