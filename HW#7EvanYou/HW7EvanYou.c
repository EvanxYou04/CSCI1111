//HW#7EvanYou.c
#include <stdio.h>

//Function Prototypes
char get_choice(void);
char get_first(void);
double multiply(double i, double n);
double divide(double i, double n);
double add(double i, double n);
double subtract(double i, double n);


int main(void)
{
    printf("HW#7 by Evan You\n");

    return 0;
}

//function definition
char get_first(){
    int ch;
    
    ch = getchar();
    while ( getchar() != '\n')
        continue;
    return ch;


}
char get_choice(void){
    int ch;

    printf("Please enter the letter of your choice: \n");
    printf("a.addition      s.subtraction\n");
    printf("m.multiplication        d.division\n");
    printf("q.quit                             \n");
    ch = get_first();
    while ( ch == 'a')
    {
        /* code */
    }
    
}
double add(double i, double n){
    return i + n;
}