//practice the use of pointers
#include <stdio.h>

void swap(int *n1, int *n2);

int main(void)
{
    int num1 = 0, num2 = 0; 
    printf("Enter a two integers (enter q to quit): ");
    while(scanf("%d%d", &num1, &num2) > 1) 
    {
        swap(&num1, &num2);
        printf("The pair of numbers in order of large to small is : %d, %d\n", num1, num2);
        printf("Enter a two integers (enter q to quit): ");
    }
    printf("You have exited the program\n");
    return 0;
}
//function that swaps the value of two integers if the first one is smaller than the second one
void swap(int *n1, int *n2)
{
    int temp;
    if (*n1 < *n2) //swaps num1 and num2 
    {
        temp = *n2;
        *n2 = *n1;
        *n1 = temp;

    }
}