#include "reverse.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define SIZE 256
int main()
{
    int fd = open("test.txt", O_RDONLY);
    if (fd ==-1){
        perror("\"test.txt\"");
        exit(1);
    }
    //fprintf(stderr,"fd = %d\n", fd);
    char buff[SIZE];
    int numBytes=0;
    numBytes =read(fd, buff, SIZE);
    if (numBytes==-1){
        perror("Reading");
        exit(1);
    }
    else if (numBytes >0){
        char buff2[SIZE];
        reverseBuffer(buff, buff2, SIZE);
        if(write(1, buff2, strlen(buff2))==-1){
            perror("Writing");
            exit(1);
        }
        // int end = strlen(buff)-1;
        // for (int i = strlen(buff)-2; i>-1;i--)
        // {
        //     if(buff[i]=='\n'){
        //         if(write(1, buff+i+1, end-i)!=end-i){
        //             perror("Writing");
        //             exit(1);
        //         }
        //         end = i;
        //     }
        // }
        // //i is 0 - print first line
        // if(write(1, buff, end+1)!=end+1){
        //     perror("Writing");
        //     exit(1);
        // }
    }

    
}