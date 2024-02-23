#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;
/* pipe is unidirectional
data moves in the form of bytes stream
two end =write end and read end
fd[2] fd[0] =redauing
 take child process id;;
 in multitherad /multiproceses memeory is shared i.e head memory not stack
 int fd[2];
 pipe(fd)
 initially it is filled with garbage value so whnen we cal pipe it get fille with fd[0]=0,fd[1]=1;
 if child want to writes then close fd[0] i.e read end and to read close fd[1] for writes;
write () system call it takes 3 arguments: 1=fd[1] where it shoudl write, 2= what itshiuld writes 3= sizeof(data) need to pass 
read() system call: 1=fd[0] 2=&buf|variale to store that red data 3rd=sizeof(buf to store later read);

pipe placed in kernal memory but fifo result in file system.
so when we create pipe it is create in kernal but fifo result in our file system 
in pipe: one process writes in pipe data will be in pipe until it red by another it's child process
in fifo also once the data is red data gets loss..
disadvayages: size is limited;64kiloBYtes, unidirectional , onecthe data red it won't be there
pipe: it is a simple buffer mentained in kernal memory  

*/
int main(){
    int fd[2]={0};
    
    if(pipe(fd)==-1){//success pipe is created
        perror("error in creating pipe");
        return -1;
    }
    pid_t process_id=fork();
    if(process_id==0){//child process
    //if chil want to writes close read fd[0]
        close(fd[0]);
        string w_data="hello";
        std::cout<<"parent is writing:"<<w_data<<std::endl;
        write(fd[1],&w_data,sizeof(w_data));
        close(fd[1]);
    }else{
        string r_buf;
        close(fd[1]);//write end closed.. if don't closed unused file descriptor 
        read(fd[0],&r_buf,sizeof(r_buf));
        std::cout<<"child is reading.."<<std::endl;
        std::cout<<r_buf<<std::endl;
        close(fd[0]);
    }
    return 0;
}