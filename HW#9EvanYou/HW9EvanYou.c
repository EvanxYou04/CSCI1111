//HW8EvanYou
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NROW 3
#define NCOL 5

//function prototypes
void clearBuffer(void);
void fillArray(double ar[][NCOL], int row);
void printArray(double ar[][NCOL], int row);
double dRand(void);
double dAvg(double ar[], int col);
double dMax(double ar[][NCOL], int row);


/*
i. For each row of data print the following information on one line:
1. The row number.
2. The row’s data values.
3. The average value for the row of data.
ii. The average value of all the values—appropriately label the results.
iii. The maximum value of all the values—appropriately label the results.
*/
int main(void)
{
    printf("HW#9EvanYou \n");
    double array[NROW][NCOL], sum = 0;
    srand(time(NULL)); //seed psudeo random number generator with time
    fillArray(array, NROW);
    printArray(array, NROW);
    for (int i = 0; i < NROW; i++)  //print average of each row 
    {
        printf("\nRow #%d Avg = %.3f ", i + 1, dAvg(array[i], NCOL));
        sum += dAvg(array[i], NCOL);
    }
    printf("\nApproximate Average of all rows = %.3f\n", sum);
    printf("Max value of the 2d array = %.3f\n", dMax(array, NROW));
    return 0;
}

//clears input buffer
void clearBuffer(void)
{
    while (getchar() != '\n') ;
}

//fill a 2d array with random numbers using dRand()
void fillArray(double ar[][NCOL] , int row)
{
        for (int i = 0; i < row; i++) //row
    {
        for (int j = 0; j < NCOL; j++) //column
        {
            ar[i][j] = dRand();
        }
    }
}

void printArray(double ar[][NCOL], int row)
{
        for (int i = 0; i < row; i++) //row
    {
        printf("Row #%d: ", i + 1);
        for (int j = 0; j < NCOL; j++) //column
        {
            printf("%.3f ", ar[i][j]);
        }
        putchar('\n');
    }
}

//returns a random number 
double dRand(void)
{
    return rand() * 10.0 / RAND_MAX;
}

//returns the average of an array
double dAvg(double ar[], int col)
{
    double sum = 0;
    for (int i = 0; i < col; i++)
    {
        sum += ar[i]; //add up all the values in the array
    }
    
    return sum / col;
}


//retunrns the max value of a number in a 2d array
double dMax(double ar[][NCOL], int row)
{
    double max = ar[0][0]; //declare max at first item 
    for (int i = 0; i < row; i++) //row
    {
        for (int j = 0; j < NCOL; j++) //column
        {
            if (max < ar[i][j])
            {
                max = ar[i][j];
            }
        }
        
    }
    return max;
}

/*  Output:
HW#9EvanYou 
Row #1: 6.829 7.364 4.405 0.366 4.421 
Row #2: 4.678 6.542 9.203 8.552 9.078 
Row #3: 9.207 5.940 3.142 0.418 2.655 

Row #1 Avg = 4.677 
Row #2 Avg = 7.610 
Row #3 Avg = 4.273 
Approximate Average of all rows = 16.560
Max value of the 2d array = 9.207

*/