#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>

void *my_thread(void *ptr)
{
	printf("\nEntered pthread");
	printf("\nThread ID: %ld", pthread_self());
	sleep(2);
	printf("\n Thread stop");
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	int ret;

	ret = pthread_create(&tid, NULL, &my_thread, NULL);
	if(ret == 0)
	{
		printf("Thread created successfully\n");
	}
	else
	{
		printf("Thread creation failed");
	}
	pthread_join(tid, NULL);
	printf("\n Main function: ");
	printf("\n PID: %d\n", getpid());

	return 0;
}

