//HW#8EvanYou

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//array lengths
#define NSIZE1 4
#define NSIZE2 8

void FillArray(double vs[], int nVals); // Prototype
void ShowArray(double vs[], int nVals); //Protoype
double dAvg(double vs[], int nVals); // Prototype
double dMax(double vs[], int nVals); // Prototype

int main(void)
{
    printf("HW#8 Evan You\n");
    double array1[NSIZE1], array2[NSIZE2]; //declare arrays 
    int count;
    srand(time(NULL));  //seed psudeo-random number generator with time 
    FillArray(array1, NSIZE1);
    FillArray(array2, NSIZE2);

    //output
    printf("Data Set Analysis:\n");
    printf("Number of datasets: 2\n"); 
    printf("Set#1 : %d items\n", NSIZE1);
    printf("Set#2 : %d items\n", NSIZE2);
    printf("Set#1: Avg = %.3f: ", dAvg(array1, NSIZE1));
    ShowArray(array1, NSIZE1);
    printf("Set#2: Avg = %.3f: ", dAvg(array2, NSIZE2));
    ShowArray(array2, NSIZE2);
    printf("Set#1-Set#2: Avg= %.3f Max= %.3f\n", (dAvg(array1, NSIZE1) -  dAvg(array2, NSIZE2)) , (dMax(array1, NSIZE1) -  dMax(array2, NSIZE2)));
    return 0;
}

//Fills array with random numbers 
void FillArray(double vs[], int nVals)
{
    for (int i = 0; i < nVals; i++)
    {
        vs[i] = (rand() * 10.0 / RAND_MAX); //assign array at index i to random num 
     //   printf("vs[%d] = %f\n", i , vs[i]);
    }
    putchar('\n');
}

//prints out array values in a line
void ShowArray(double vs[], int  nVals)
{
    for (int i = 0; i < nVals; i++)
    {
        printf("%.3f ", vs[i]);
    }
    putchar('\n');
}

//returns the average of an array as a double 
double dAvg(double vs[], int nVals)
{
    double sum;
    for (int i = 0; i < nVals; i++)
    {
        sum += vs[i];
    }
    return sum / ((double)nVals); //average = sum / amount of numbers 
}

//finds the max value in an array and returns it as a double
double dMax(double vs[], int nVals)
{
    double max = vs[0];
    for (int i = 0; i < nVals; i++)
    {
        if (max < vs[i])
        {
            max = vs[i];
        }
    }
    return max;
}

