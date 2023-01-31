//HW#4EvanYou

#include <stdio.h>
#define LENGTH 50
#define INCH_PER_FEET 12

int main(int argc, char *argv[]){
    int height,feet,inches;
    int count = 0; 
    char firstName[LENGTH];
    printf("Evan You Homework#4.\n");
    printf("Enter your first name and your height in inches(q to exit): ");
    while (scanf("%s%i", firstName, &height)>1)
    {
        feet = height / INCH_PER_FEET;
        inches = height % INCH_PER_FEET;
        printf("%s's height is %d feet %d inches.\n", firstName, feet, inches);
        count++;
        printf("Enter your first name and your height in inches(q to exit): ");
    }
    printf("Done! Entered %d sets of name(s) and height(s).\n", count);
    return 0;

}

/*
Output:
Evan You Homework#4.
Enter your first name and your height in inches(q to exit): Evan 67
Evan's height is 5 feet 7 inches.
Enter your first name and your height in inches(q to exit): Lindsay 63
Lindsay's height is 5 feet 3 inches.
Enter your first name and your height in inches(q to exit): q q
Done! Entered 2 sets of name(s) and height(s).


*/