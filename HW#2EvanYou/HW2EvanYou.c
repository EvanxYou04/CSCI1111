//
// HW#1EvanYou
//
//
//

#include <stdio.h>

int main(void) {
    float cups, pint, oz, tbsp, tsp; 
    printf("HW #2 by Evan You\n");
    printf("Enter the number of cups to be converted.  ");
    scanf("%f", &cups);
    pint = cups / 2.0;
    oz = cups * 8.0;
    tbsp = cups * 16.0;
    tsp = tbsp * 3.0;
    printf("%.3f cups = %9.3f pint\n= %9.3f ounces\n= %9.3f tablespoons\n= %9.3f teaspoons\n", cups, pint, oz, tbsp, tsp);




}
/* 
Output:

HW #2 by Evan You
Enter the number of cups to be converted.  3.2
3.20 cups = 1.600 pints    
          = 25.600 ounces   
          = 51.200 tablespoons 
          = 153.600 teaspoons
          
*/