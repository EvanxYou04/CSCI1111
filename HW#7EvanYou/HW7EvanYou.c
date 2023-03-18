//HW#7EvanYou.c
#include <stdio.h>
#include <ctype.h>

//Function Prototypes
char menuPrompt(void);
char get_first(void);
double multiply(double i, double n);
double divide(double i, double n);
void add(void);
double subtract(double i, double n);


int main(void)
{
    printf("HW#7 by Evan You\n");
    int choice;
    menuPrompt();
    while ((choice = get_first()) != 'q')
    {
        switch (choice)
        {
        case 'a': printf("addition in progress.\n");
            break;
        case 'b': printf("subtraction in progress.\n");
            break;
        case 'c': printf("multiplication in progress.\n");
            break;
        case 'd': printf("division in progress.\n");
            break;
        default: printf("PROGRAM ERROR\n");
            break;
        }
        menuPrompt();
    }
    

    return 0;
}

//function definition
char get_first()
{
    int ch;
    
    ch = tolower(getchar());
    while ( getchar() != '\n')
        continue;
    return ch;


}
char menuPrompt(void)
{
    int ch;
    //menu
    printf("Please enter the letter of your choice: \n");
    printf("a.addition              s.subtraction\n");
    printf("m.multiplication        d.division\n");
    printf("q.quit                             \n");
    // ch = get_first();
    // while ( (ch < 'a' || ch > 'd') && ch != 'q') 
    // {
    //     printf("Please respond with a, b, c, or q.\n");
    //     ch = get_first(); 
    // }
    // return ch;
}
void add(void)
{
    int num1, num2, sum;
    printf("Enter integer one: ");
    scanf("%d", &num1);
    putchar('\n');
    printf("Enter number two:");
    scanf("%d", &num2);
    putchar('\n');
    sum = num1 + num2;
    printf("%d + %d = %d",num1, num2, sum);
    
}