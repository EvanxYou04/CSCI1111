//HW10EvanYou
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NROW 5
#define NCOL 6

//function prototypes
void fillArray(double ar[][NCOL], int row);
void printArray(double ar[][NCOL], int row);
void dSelectionSort(double ar[], int col);
double dRand(void);
double dAvg(double ar[], int col);
double dMax(double ar[][NCOL], int row);



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
        for (int j = 0; j < NCOL; j++)
        {
           sum += array[i][j];
        }
        
    }
    printf("\nAverage of all rows = %.3f\n", sum / (double)(NROW * NCOL));
    printf("Max value of the 2D array = %.3f\n", dMax(array, NROW));
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
/*starts from first index , finds min value afer each run and swaps with current position*/
void dSelectionSort(double ar[], int col)
{
    //travel one by one through the array
    for (int i = 0; i < col - 1; i++)
    {
        
        int min = i; //change index of where min value is
        for (int j = i + 1; j < col ; j++)     
        {
            if (ar[j] < ar[min])
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

*/