//
//Purpose: Convert Height from inches to Feet and Inches
//

#include <stdio.h>
#define FEET_PER_INCH 12

int main(int argc, char *argv[])
{
    int inch, feet, mod, count = 0;
    printf("Converts height in inches to feet and inches\n");
    printf("Enter height in inches(q to quit): ");
    while(scanf("%d",&inch)>0)
    {
        feet = inch / FEET_PER_INCH; //integer division
        mod = inch % FEET_PER_INCH; 
        printf("%d' %d\"\n",feet, mod);
        printf("Enter height in inches(q to quit): ");
        count++;
    }
    printf("Done! %i Heights converted.\n", count);
    return 0;
}