/*Exercise: Write a program that asks the user for the size of the input, 
dynamically allocates the array to hold this size, 
then asks the user for the string, 
stores this string in a dynamically allocated array, 
and prints it back.
Example of output:
Enter the size of input: 50
Please, enter the string: I like NIC
You entered: I like NIC
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //char string[100];
    printf("Enter the size of input: ");
    int size=0;
    scanf("%d", &size);
    printf("Enter the size of input: %d\n", size);
    //char str[size];
    char * str = calloc(sizeof(char), size);
    printf("Please, enter the string: ");
    getchar();
    fgets(str, size, stdin);
    printf("You entered: %s\n", str);
    free(str);
    return 0;
}