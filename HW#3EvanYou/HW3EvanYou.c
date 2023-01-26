//
//HW#3EvanYou
//January 23, 2023
//
//

#include <stdio.h>
#include <string.h> 
#define LENGTH 50

int main()
{
    printf("HW#3 by Evan You\n");
    char firstName[LENGTH], lastName[LENGTH]; //initalize first and last name variables
    int firstLen, lastLen;
    float num1;
    double num2;

    printf("Type in your first and last name: "); //prompt  
    scanf("%s%s", firstName, lastName);

    //find the length of first and last name
    firstLen = strlen(firstName); 
    lastLen = strlen(lastName);

    printf("%s %s\n",firstName, lastName); // prints first and last name
    printf("%*d %*d\n", firstLen, firstLen, lastLen,lastLen); // print number right justified

    num1 = 1.0 / 3.0; //float
    num2 = 1.0 / 3.0; //double

    printf("float: %.4f %.8f %.16f\n", num1, num1, num1);
    printf("double: %.4lf %.8lf %.16lf\n", num2, num2, num2);
    
    return 0;

    /*
    Output:
HW#3 by Evan You
Type in your first and last name Evan You
Evan You
   4   3
float: 0.3333 0.33333334 0.3333333432674408
double: 0.3333 0.33333333 0.3333333333333333
    
    */
}
