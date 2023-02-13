//HW#6EvanYou
#include <stdio.h>
#include <limits.h>

#define MAX 10
#define PROMPT "Enter an integer for n! Enter up to 10 values! (Enter q to exit):"

unsigned long long Factorial(unsigned int n);

int main(void) {
    int nums[MAX], facts[MAX]; 
    int status = 1, nFacts;
    printf("HW#6 Evan You\n");
    printf(PROMPT);
    
    for (int index = 0; index < MAX && status; index++)
    {
        status = scanf("%d", &nums[index]);
        nFacts = index + 1;
    }
    printf("All integer(s) sucessfully read.\n");
    // printf("nFacts = %d\n", nFacts);
    for (int index = 0; index < nFacts; index++)
        printf("%4d", nums[index]);
    printf("\n");


    return 0;
}

unsigned long long Factorial(unsigned int n){
    unsigned long long fact = 1;
    for (unsigned long long i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;
}