#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define COL 5
#define ROW 6

//function prototype

void dSelectionSort(double ar[], int col);
void fillArray(double ar[][COL], int row);
void printArray(double ar[][COL], int row);
void swap(double * xp, double * yp);
double dRand(void);


int main(void)
{
    srand(time(NULL));
    double array[ROW][COL];
    fillArray(array, ROW);
    printArray(array, ROW);
    printf("Sorted: \n");
    for (int i = 0; i < ROW; i++)
    {
        dSelectionSort(array[i], COL);
    }
    printArray(array, ROW);
    

    return 0;
}

//fill a 2d array with random numbers using dRand()
void fillArray(double ar[][COL] , int row)
{
        for (int i = 0; i < row; i++) //row
    {
        for (int j = 0; j < COL; j++) //column
        {
            ar[i][j] = dRand();
        }
    }
}

void printArray(double ar[][COL], int row)
{
        for (int i = 0; i < row; i++) //row
    {
        printf("Row #%d: ", i + 1);
        for (int j = 0; j < COL; j++) //column
        {
            printf("%.3f ", ar[i][j]);
        }
        putchar('\n');
    }
}

double dRand(void)
{
return rand() % 10 + 1;
}

void swap(double * xp, double * yp)
{
    double tmp = *xp;
    *xp = *yp;
    *yp = tmp;


}

/*starts from first index , finds min value afer each run and swaps with current position*/
void dSelectionSort(double ar[], int col)
{

    for (int i = 0; i < col - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < col ; j++)     
        {
            if (ar[j] < ar[min])
            {
            min = j;
            }
        //swap values
            if (min != i)
            {
                swap(&ar[min], &ar[i]);
            }
        
      }
      
    }
    
}