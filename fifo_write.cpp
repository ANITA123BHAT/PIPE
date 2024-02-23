#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h> //for mkfifo
#include <fcntl.h>

using namespace std;
int main(int argc, char *argv[])
{
    int fd;
    mkfifo("file1", 0666); // 666 for read&write 0777 is R/W/EXEC
    fd = open("file1", O_WRONLY);
    // char buf='a';
    // write(fd,&buf,sizeof(buf));

    //    char buf[50]="HELLO";
    string buf = "hello";
    write(fd, buf.c_str(), buf.length());
    close(fd);
    return 0;
}
