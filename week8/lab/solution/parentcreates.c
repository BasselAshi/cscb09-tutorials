#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {

	int i;
	int n;
	int num_kids;

	if(argc != 2) {
		fprintf(stderr, "Usage: forkloop <numkids>\n");
		exit(1);
	}

	num_kids = atoi(argv[1]);

	for(i = 0; i < num_kids; i++) {
		n = fork();
		if(n < 0) {
			perror("fork");
			exit(1);
		}

		if  (n == 0) break;;

		printf("%d -> %d\n", getpid(), n);
	}

	for (int i = 0; i < num_kids; i++) {
		int status;
		wait(&status);
	}

	return 0;
}
