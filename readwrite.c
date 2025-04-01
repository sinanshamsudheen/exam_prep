#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd=open("test.txt",O_RDONLY);
    if(fd<0){
        perror("fd error");
        return 1;
    }
    char buffer[100];
    int bytesRead=read(fd,buffer,sizeof(buffer));
    write(STDOUT_FILENO,buffer,bytesRead);
    close(fd);
    return 0;
}