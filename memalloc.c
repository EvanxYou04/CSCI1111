#include <stdio.h>
#include <stdlib.h>

int * MakeArray(int elem, int val);
void ShowArray(const int ar[], int n);

int main(void) 
{
    int * pa, size, value;
    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0) 
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = MakeArray(size, value);
        if (pa) 
        {// Check that the memory was allocated.
            ShowArray(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    char *pchar = "1234";
    printf("size of pchar:%lu \n", sizeof(pchar));
    return 0;
}

int * MakeArray(int elem, int val)
{
    int *pi, *pend, *ptr;
    ptr = (int *) malloc(elem * sizeof(int));
    if(ptr)
    {         //checks if memory was allocated
        for (pi = ptr, pend = ptr + elem; pi < pend; pi++)
        {
            *pi = val; //sets value at each spot
        }
    }
    return ptr;
}

void ShowArray(const int ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%6d ", ar[i]);
        if(i % 8 == 7) printf("\n");
    }
    printf("\n");
    
}
