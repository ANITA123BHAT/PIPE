#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd1,fd2,i;
	char wbuf[50]={0},rbuf[50];
	fd1 = open("f1",O_WRONLY);
	fd2 = open("f2",O_RDONLY);
	i = fork();
	if(i==0)
	{
		while(1)
		{
			read(fd2,rbuf,50);
			printf("%s\n",rbuf);
		}
	}
	else
	{
		while(1)
		{
			scanf("%s",wbuf);
			write(fd1,wbuf,strlen(wbuf)+1);
		}
	}
	close(fd1);
	close(fd2);
}
