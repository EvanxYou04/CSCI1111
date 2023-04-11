//HW#12EvanYou
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double dRand(void); //return a random double value
int Setup(int *pnChan, int *pnPt); 
int CollectData(int nChan, int nPt, double Data[][nPt]);

int main(void)
{
    printf("Evan You HW#8 \n");
    srand(time(NULL));

    return 0;
}

double dRand(void)
{
    return rand() * (10/RAND_MAX);
}