//HW#5EvanYou
#include <stdio.h>

#define PROMPT "Enter an integer less than 21 for n! (enter q to exit): "

int main(int argc, char *argv[])
{
    int fact;
    unsigned long long n = 1;
    printf("HW#05EvanYou\n");
    printf(PROMPT);
    while((scanf("%d", &fact) > 0  && fact < 21))
    {
        n = 1;
        for (int i = 1; i<fact; i++){
            printf("n = %llu\n", n);
            n += i*n;
        }
        printf("%2d! = %llu\n",fact, n);
        printf(PROMPT);
    }

    printf("Done!\n");

    return 0;
}

/*
Output:
HW#05EvanYou
Enter an integer less than 21 for n! (enter q to exit): 5
5! = 120
Enter an integer less than 21 for n! (enter q to exit): 0
0! = 1
Enter an integer less than 21 for n! (enter q to exit): q
Done!
*/