#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
int main(){
  DIR *dir = opendir(".");
  struct dirent *entry;

  while((entry=readdir(dir))!=NULL){
    printf("files %s ",entry->d_name);
  }
  closedir(dir);
  return 0;
}