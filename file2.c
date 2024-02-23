#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd1,fd2,i;
	char rbuf[50]={0},wbuf[50];
	fd1 = open("f1",O_RDONLY);
	fd2 = open("f2",O_WRONLY);
	i=fork();
	if(i==0)
	{
		while(1)
		{
			read(fd1,rbuf,50);
			printf("%s\n",rbuf);
		}
	}
	else
	{
		while(1)
		{
			scanf("%s",wbuf);
			write(fd2,wbuf,strlen(wbuf)+1);
		}
	}
	close(fd1);
}
