#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pd1[2],pd2[2],i;
	char buf[20]={0};
	pipe(pd1);
	pipe(pd2);
	printf("pd1[0] = %d\n",pd1[0]);
	printf("pd1[1] = %d\n",pd1[1]);
	printf("pd2[0] = %d\n",pd2[0]);
	printf("pd2[1] = %d\n",pd2[1]);
	i=fork();
	if(i==0)
	{
		printf("child process\n");
		read(pd1[0],buf,12);
		printf("read data from parent = %s\n",buf);
		write(pd2[1],"Hello parent",13);
		printf("child writes\n");
		printf("child completes\n");
	}
	else
	{
		char rbuf[20] = {0};
		printf("parent process\n");
		write(pd1[1],"Hello Child",12);
		printf("Parent writes\n");
		read(pd2[0],rbuf,13);
		printf("read data from child  = %s\n",rbuf);
		printf("parent completes\n");
		wait(0);
	}

}
