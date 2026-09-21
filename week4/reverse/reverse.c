#include "reverse.h"
#include <string.h>

void reverseBuffer(char buff[], char newBuff[], int size)
{
    int end = strlen(buff)-1;
    int position = 0;
    for (int i = strlen(buff)-2; i>-1;i--)
    {
        if(buff[i]=='\n'){
            strncpy(newBuff + position, buff+i+1, end-i);
            position +=end-i;
            end = i;
        }
    }
    //i is 0 - print first line
    strncpy(newBuff + position, buff, end+1);
}