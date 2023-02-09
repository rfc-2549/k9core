#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void
list_signals(void)
{
	puts("1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) "
		"SIGTRAP");
	puts("6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) "
		"SIGUSR1");
	puts("11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) "
		"SIGTERM");
	puts("16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) "
		"SIGTSTP");
	puts("21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) "
		"SIGXFSZ");
	puts("26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR");
	puts("31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) "
		"SIGRTMIN+3");
	puts("38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) "
		"SIGRTMIN+8");
	puts("43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) "
		"SIGRTMIN+12	47) SIGRTMIN+13");
	puts("48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) "
		"SIGRTMAX-13	52) SIGRTMAX-12");
	puts("53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) "
		"SIGRTMAX-8	57) SIGRTMAX-7");
	puts("58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) "
		"SIGRTMAX-2");
	puts("63) SIGRTMAX-1	64) SIGRTMAX");
}

int
main(int argc, char *argv[])
{

	int sig = 0;
	pid_t pid;
	if(argc == 1) {
		fprintf(stderr, "expected something\n");
		return 1;
	}
	if(argv[1][1] == 'l') {
		list_signals();
		return 0;
	}
	switch(argc) {
		case 2:
			sig = 15;
			pid = atoi(argv[1]);
			break;
		case 3:
			sig = abs(atoi(argv[1]));
			pid = abs(atoi(argv[2]));
			break;
		default:
			fprintf(stderr, "Specify who to kill\n");
			return 1;
	}
	kill(pid, sig);
	return 0;
}
