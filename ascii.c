#include <stdio.h>

int main(int argc, char *argv[]){
   int x[5];
   int * ptr = x;
   printf("Size of int : %lu bytes\n", sizeof(x));
   printf("Size of ptr : %lu bytes\n", sizeof(ptr));

}