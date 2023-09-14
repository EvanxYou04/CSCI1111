#include <stdio.h>

int main(int argc, char *argv[])
{
    char *(ptr1[10]);
    char (*ptr2)[10]= &("Hello ME!");
    printf("size of ptr1: %lu\n size of ptr2:%lu\n", sizeof(ptr1), sizeof(ptr2));
    
}