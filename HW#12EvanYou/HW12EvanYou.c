//HW#12EvanYou
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define PROMPT "Enter number of input channels from 2 to 10 (enter -1 to exit): "

void menu(void);
void clearLine();
double dRand(void); //return a random double value
char getFirst(void);
int Setup(int *pnChan, int *pnPt); 
int CollectData(int nChan, int nPt, double Data[][nPt]);

int main(void)
{
    printf("Evan You HW#12 \n");
    int channels, points;
    long memSize;
    srand(time(NULL)); //seed randum number with time
    while(Setup(&channels, &points) != -1)
    {
        memSize = sizeof(double) * channels * points;
        double (*pData)[points] = (double (*)[points]) malloc(memSize);
        if(pData) 
        {
            CollectData(channels, points, pData);
            //output prompts
            printf("Number of channels : %d\n", channels);
            printf("Number of data points: %d\n", points);
            printf("Size of data: %ld bytes\n", memSize);
            printf("Address of memory allocated: %p\n",pData);
            free(pData);
        }
        else
        {
            puts("\nNot enough memory available, please select fewer\n"
   			"channels and/or fewer data points.");
        }
        
    }
    fputs("Done.\n", stdout);
    
    return 0;
}

void menu(void)
{
    printf("Please enter the number of data points: \n");
    printf("a.2048      b.4096\n");
    printf("c.8192      d.quit\n");
}

//clears buffer
void clearLine(void)
{
    while(getchar() != '\n') ;
}

//get choice
char getFirst(void)
{
    int ch;

    ch = tolower(getchar());
    clearLine();

    return ch;
}


double dRand(void)
{
    return rand() * (10.0/RAND_MAX);
}

//asks for channel size and number of data points
int Setup(int *pnChan, int *pnPt)
{
    int choice,chans;
    fputs(PROMPT, stdout);
    while(scanf("%d", pnChan) == 1 && (*pnChan >= 2 && *pnChan <= 10))
    {
        clearLine();
        menu();
        switch (choice = getFirst())
        {
            case 'a':  
                *pnPt = 2048;
                return 0;
            case 'b':             
                *pnPt = 4096;
                return 0;
            case 'c': 
                *pnPt = 8192;
                return 0;
            case 'd': 
                return -1;
            default: 
                fputs("Try again", stdout);
                break;
        }
        menu();
    }
    
    return -1;
}

//puts random values into the arrays
int CollectData(int nChan, int nPt, double Data[][nPt])
{ 
    double *pi = (double *) Data;
    double *piend = pi + nChan*nPt;
    while (pi < piend)
        *pi++ = dRand();
    return 0;
}
/*output 
Evan You HW#12 
Enter number of input channels from 2 to 10 (enter -1 to exit): 2
Please enter the number of data points: 
a.2048      b.4096
c.8192      d.quit
a
Number of channels : 2
Number of data points: 2048
Size of data: 8 bytes
Address of memory allocated: 0x141808200
Enter number of input channels from 2 to 10 (enter -1 to exit): -1
Done.
*/