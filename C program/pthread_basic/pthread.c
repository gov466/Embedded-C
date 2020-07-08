#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *entry_point(void *value)
{
	printf("hello from second thread");
	int *num =(int *) value;
	printf("the value of value is %d",*num);
	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t thread;
	printf("hello from first thread\n");
	int num=21;
	pthread_create(&thread,NULL,entry_point,&num);
	pthread_join(thread,NULL);
	return EXIT_SUCCESS;
}
