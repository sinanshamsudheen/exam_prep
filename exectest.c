#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  execl("/bin/ls","ls","-a",NULL);
  return 0;
}