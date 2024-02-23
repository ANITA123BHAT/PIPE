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
    fd = open("file1", O_RDONLY);
    char buf[50];
    // read(fd,&buf,sizeof(buf));
    // string buf;
    read(fd, &buf, sizeof(buf));
    std::string rev(buf);
    cout << rev << endl;
    std::cout << "the red data is:" << buf << std::endl;
    close(fd);
    return 0;
}
