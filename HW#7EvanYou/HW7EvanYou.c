//HW#7EvanYou.c
#include <stdio.h>
#include <ctype.h>

//Function Prototypes
void menuPrompt(void);
char get_first(void);
float getFloat(int num);
void clearLine(void);



int main(void)
{
    printf("HW#7 by Evan You\n");
    int choice;
    float x,y;
    menuPrompt();
    while ((choice = get_first()) != 'q')
    {
        switch (choice)
        {
        case 'a':   
            x = getFloat(1);
            y = getFloat(2);
            printf("%g + %g = %g " , x , y , x+y);
            break;
        case 's':             
            x = getFloat(1);
            y = getFloat(2);
            printf("%g - %g = %g " , x , y , x-y);
            break;
        case 'm': 
            x = getFloat(1);
            y = getFloat(2);
            printf("%g * %g = %g " , x , y , x*y);
            break;
        case 'd': 
            x = getFloat(1);
            y = getFloat(2);
            printf("%g / %g = %g " , x , y , x/y);
            break;
        default: printf("PROGRAM ERROR\n");
            break;
        }
        menuPrompt();
    }
    

    return 0;
}

void clearLine(void)
{
    while((getchar()) != '\n') ;
    
}

//function definition
char get_first()
{
    int ch;
    
    ch = tolower(getchar());
  //  clearLine();
    return ch;


}
void menuPrompt(void)
{
    int ch;
    //menu
    printf("Please enter the letter of your choice: \n");
    printf("a.addition              s.subtraction\n");
    printf("m.multiplication        d.division\n");
    printf("q.quit                             \n");
}

float getFloat(int num)
{
    int ch;
    float flt;
    if (num == 1) printf("Enter the 1st floating point value: ");
    else printf("Enter the 2nd floating point value: ");
    while (scanf("%f",&flt)==0)
    {
        while ( (ch = getchar()) != '\n') putchar(ch);
        printf(" is not a number. Please try again\n");
    }
    clearLine();
    return flt;

}