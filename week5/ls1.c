#include <stdio.h>
#include <dirent.h>

int main(int arc, char *argv[])
{
    DIR *pDir;
    struct dirent *pEntry;

    if ((pDir = opendir("."))==NULL){
        perror("Opening directory");
    }else{
        while ((pEntry = readdir(pDir))!=NULL){
            if (pEntry->d_name[0] != '.'){
                printf("%s\n", pEntry->d_name);
            }
        }
    }
    closedir(pDir);
}
