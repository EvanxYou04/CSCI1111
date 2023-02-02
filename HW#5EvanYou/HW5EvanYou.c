//HW#5EvanYou
#include <stdio.h>

#define PROMPT "Enter an integer less than 21 for n! (enter q to exit): "

int main(int argc, char *argv[])
{
    int fact;
    long long n;
    printf("HW#05EvanYou\n");
    printf(PROMPT);
    while(scanf("%d", &fact)> 0)
    {
        n = 1; // 0! = 1
        for (int i = 0; i<fact; i++){
            n += i*n;
            
        }
        printf("%d! = %lld\n",fact, n);
        printf(PROMPT);
    }

    return 0;
}