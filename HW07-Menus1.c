// HW7-Menus1 w/o q to quit in GetFloat.
#include <stdio.h>
#include <ctype.h>
void ClearLine(void);
int GetFirst(void);
float GetFloat(int num) ;
void MenuPrompt(void);

int main(void)
{
	int ch;
	float x, y;
	printf("HW #7.1:  Ken Pottebaum\n\n");
	MenuPrompt();
	while ( (ch=GetFirst()) != 'q') {
		// Get float values, ch to a space if GetFloat aborted.
		switch (ch) {
			case 'a':	x = GetFloat(1);
						y = GetFloat(2);
						printf(" %g + %g = %g\n\n",x,y,x+y);
						break;
			case 's': 	x = GetFloat(1);
						y = GetFloat(2);
						printf(" %g - %g = %g\n\n",x,y,x-y);
						break;
			case 'm': 	x = GetFloat(1);
						y = GetFloat(2);
						printf(" %g * %g = %g\n\n",x,y,x*y);
						break;
			case 'd': 	x = GetFloat(1);
						y = GetFloat(2);
						while (y==0.0) {
						 	printf("Please enter a nonzero value.\n");
						 	y = GetFloat(2);
		 				}
						printf(" %g / %g = %g\n\n",x,y,x/y);
		}
		MenuPrompt();
	}
	return 0;
}

// ClearLine clears characters out of the input buffer
// until an '\n' is encountered.
void ClearLine(void) {
	while ((getchar()) != '\n') ; // Clear line to '\n'.
}

// GetFirst returns the first character from the input
// buffer as a lower case character and clears out the 
// remaining characters to and including '\n'.
int GetFirst(void) {
	int ch;
	ch = tolower(getchar());  // Get first character.
	ClearLine();		  // Clear line to '\n'.
	return ch;
}

// GetFloat reads a float value and clears any
// garbage entered.
float GetFloat(int num) {
	int ch;
	float Flt;
	if (num==1) printf("Enter the 1st floating point value:  ");
	else printf("Enter the 2nd floating point value:  ");
	while (scanf("%f",&Flt)==0) {
		// Clear out and echo garbage and prompt for new value.
		while ((ch=getchar())!='\n')
			putchar(ch);
		printf(" is not a number.\nPlease enter a number.\n");
	}
	ClearLine();
	return Flt;
}

// Function to print the menu prompt.
void MenuPrompt(void) {
	printf("Enter the letter for the operation of your choice:\n");
	printf("  a. add              s. subtract\n");
	printf("  m. multiply         d. divide       q. quit\n");
}

//	HW #7.1:  Ken Pottebaum
//
//	Enter the letter for the operation of your choice:
//	  a. add              s. subtract
//	  m. multiply         d. divide       q. quit
//	add
//	Enter the 1st floating point value (q to quit):  4.2312
//	Enter the 2nd floating point value (q to quit):  23
//	 4.2312 + 23 = 27.2312
//	
//	Enter the letter for the operation of your choice:
//	  a. add              s. subtract
//	  m. multiply         d. divide       q. quit
//	d
//	Enter the 1st floating point value (q to quit):  9
//	Enter the 2nd floating point value (q to quit):  2.3
//	 9 / 2.3 = 3.91304
//	
//	Enter the letter for the operation of your choice:
//	  a. add              s. subtract
//	  m. multiply         d. divide       q. quit
//	d
//	Enter the 1st floating point value (q to quit):  23
//	Enter the 2nd floating point value (q to quit):  0
//	Please enter a nonzero value.
//	Enter the 2nd floating point value (q to quit):  4
//	 23 / 4 = 5.75
//	
//	Enter the letter for the operation of your choice:
//	  a. add              s. subtract
//	  m. multiply         d. divide       q. quit
//	q
//	
//	--------------------------------
//	Process exited after 130.8 seconds with return value 0
//	Press any key to continue . . .			

