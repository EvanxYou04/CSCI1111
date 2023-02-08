#include <stdio.h>

int main(int argc, char *argv[]){
   for (int i = 0; i<argc;i++){
    printf("Index: %3d Data: %s\n",i, argv[i]);
   } 
   printf("Done.\n");
   printf("%d", argv[1]);
   if((char)argv[1] == 99){
    printf("True\n");
   }
   else
   {
    printf("False\n");
   }


}