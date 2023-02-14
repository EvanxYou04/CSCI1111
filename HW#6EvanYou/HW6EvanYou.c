//HW#6EvanYou
#include <stdio.h>
#include <limits.h>

#define MAX 10
#define PROMPT "Enter an integer for n! Enter up to 10 values! (Enter q to exit):"

unsigned long long Factorial(unsigned int n);

int main(void) {
    int nums[MAX], facts[MAX]; 
    int nFacts;
    unsigned short nMax = USHRT_MAX, i=1;
    printf("HW#6 Evan You\n");
    printf(PROMPT);
    
    for (int index = 0; index < MAX && scanf("%d", &nums[index]); index++)
    {
        nFacts = index;
    }
    printf("All integer(s) sucessfully read.\n");
    for (int index = 0; index <= nFacts; index++)
    {
        printf("%-10d %-10llu\n", nums[index], Factorial(nums[index]));
    }
    printf("\n");

        while (nMax > 1)
    {
        nMax /= ++i;
    }
    printf("The highest n for largest possible unsigned short value of n! is:%hu\n", i);

    return 0;
}

unsigned long long Factorial(unsigned int n){
    unsigned long long fact = 1;
    for (unsigned long long i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;
}