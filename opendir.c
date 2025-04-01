#include<stdio.h>
#include<dirent.h>
int main(){
    DIR *dir=opendir(".");
    struct dirent *entry;
    if(dir==NULL){
        perror("opendir");
        return 1;
    }
    while((entry==readdir(dir))!=NULL){
        printf("%s\n",entry->d_names);
    }
    closedir(dir);
    return 0;
}
