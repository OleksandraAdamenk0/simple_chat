#include "server.h"
#include "libmx.h"

int main(int argc, char *argv[]) {
	// first argument - network port
	// if 0 or more than 1 argument is given - show usage
	// if wrong argument for the network port is given - show usage
	int port = mx_atoi(argv[1]);
	if (argc != 2 || port <= 0) {
		mx_printstr("Usage: ./server [network port]\n");
		exit(EXIT_FAILURE);
	}

	// run programm as a deamon
	 mx_run_daemon();
	// run logic
	mx_run_server(port);
	return 0;
}
