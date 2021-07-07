#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%ld\n", time.tv_sec);
	printf("%ld\n", time.tv_sec);
	printf("%ld\n", time.tv_sec);
	// usleep(1000);
	// gettimeofday(&time, NULL);
	// printf("%ld\n", time.tv_usec);
}
