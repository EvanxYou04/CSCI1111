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
  Row        0       1       2       3       4       5       Average
   0   -6.657   -6.147   -1.286   -0.021   -5.618   -8.471   -4.700
   1   -4.877   -9.433   -8.789   -4.798   -6.323   -7.649   -6.978
   2   -2.944   -3.805   -5.313   -5.628   -0.570   -4.498   -3.793
   3   -5.969   -6.938   -4.577   -3.957   -8.213   -0.341   -4.999
   4   -2.276   -5.023   -9.297   -9.361   -5.793   -7.991   -6.623

Storted Array:
  -0.021   -1.286   -6.147   -6.657   -5.618   -8.471 
  -4.798   -4.877   -7.649   -6.323   -8.789   -9.433 
  -2.944   -3.805   -4.498   -0.570   -5.313   -5.628 
  -0.341   -3.957   -4.577   -5.969   -6.938   -8.213 
  -2.276   -5.023   -7.991   -5.793   -9.297   -9.361 

Average of all rows =   -5.419
Max value of the 2D array =   -0.021
*/