//HW10EvanYou
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NROW 5
#define NCOL 6

//function prototypes

void fillArray(double ar[][NCOL], int row);
void printRow(double ar[], int col); //col used as number of values in a 1d array
void dSelectionSort(double ar[], int col);
double dRand(void);
double dAvg(double ar[], int col);
double dMax(double ar[][NCOL], int row);


/*
In your main function, print out the results in the following order and format:
i. For each row of data print the following information on one line:
1. The row number.
2. The average value for the row of data.
3. The sorted row values (in descending order).
ii. The average value of all the values—appropriately label the results.
iii. The maximum value of all the values—appropriately label the results.
*/
int main(void)
{
    printf("HW#10EvanYou \n");
    double array[NROW][NCOL], sum = 0;
    srand(time(NULL)); //seed psudeo random number generator with time
    fillArray(array, NROW); //Fill array with random number
    //output results
    printf("%5s ", "Row");
    for (int c = 0; c <NCOL; c++)
    {
        printf("%8d", c);
    }
    printf("       Average\n");
    for (int r=0; r<NROW; r++) 
    {
    printf("%4d ",r);
        for (int c=0; c<NCOL; c++)
        {
        printf("%8.3lf ", array[r][c]);
        sum += array[r][c];
        }
    printf("%8.3lf\n", dAvg(array[r], NCOL));
    }
    printf("\nStorted Array:\n");
    //sort each row
    for (int i = 0; i < NROW; i++)
    {
        dSelectionSort(array[i], NCOL);
        printRow(array[i], NCOL);
    }
    
    printf("\nAverage of all rows = %8.3lf\n", sum / (double)(NROW * NCOL));
    printf("Max value of the 2D array = %8.3lf\n", dMax(array, NROW));
    return 0;
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

//prints out array 
void printRow(double ar[], int col)
{
        for (int i = 0; i < col; i++) //row
    {
        printf("%8.3lf ", ar[i]);   
    }
    putchar('\n');
}
/*starts from first index , finds min value afer each run and swaps with current position*/
void dSelectionSort(double ar[], int col)
{
    //travel one by one through the array
    for (int i = 0; i < col - 1; i++)
    {
        
        int min = i; //change index of where min value is
        for (int j = i + 1; j < col ; j++)     
        {
            if (ar[j] > ar[min])
            {
            min = j;
            }
        //swap values
            if (min != i)
            {
                double tmp = ar[i];
                ar[i] = ar[min];
                ar[min] = tmp;
            }
        
      }
      
    }
    
}
//returns a random number 
double dRand(void)
{
    return rand() * (-10.0) / RAND_MAX;
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
HW#10EvanYou 
Row #1: Avg = -3.467: -0.794 -9.003 -3.050 -3.968 -3.661 -0.323 
Row #2: Avg = -5.565: -2.179 -6.667 -9.473 -7.348 -3.028 -4.694 
Row #3: Avg = -5.662: -1.480 -7.500 -7.063 -8.963 -3.738 -5.226 
Row #4: Avg = -7.224: -8.278 -1.417 -8.775 -8.587 -7.778 -8.509 
Row #5: Avg = -4.804: -6.093 -6.723 -3.958 -1.837 -2.638 -7.576 

Storted Array:
-0.323 -0.794 -3.050 -3.661 -3.968 -9.003 
-2.179 -4.694 -3.028 -6.667 -7.348 -9.473 
-1.480 -5.226 -3.738 -7.063 -7.500 -8.963 
-1.417 -8.278 -8.509 -7.778 -8.587 -8.775 
-1.837 -3.958 -6.093 -6.723 -2.638 -7.576 

Average of all rows = -5.344
Max value of the 2D array = -0.323

*/