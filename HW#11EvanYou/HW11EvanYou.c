#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 41
#define PROMPT "Enter a line of text (press enter to quit): "

void clearBuffer(void);
int CharIsAt(char * pStr, char ch, int loc[], int mLoc);
int GetFirst(void);

int main(void)
{
    int i, ch, loc[SIZE], charFinder;
    char words[SIZE];
    char *pc = words;

    printf(PROMPT);
    while (fgets(words, SIZE, stdin) != NULL && words[0] != '\n')
    {
       //clear new line char from words 
        while (*pc != '\0' && *pc != '\n') pc++;
        if (*pc == '\n')
            *pc = '\0';
        else  // words[i] == '\0'
            while (getchar() != '\n') ; // clear buffer 
    printf("Enter a character to search for: ");
    ch = GetFirst();
    charFinder = CharIsAt(words, ch, loc, strlen(words));
    //output prompts
    printf("String output: %s\n", words);
    printf("Character to search : %c\n", ch);
    printf("The number of locations at which the character was found: %d\n", charFinder);
    printf("The index of each occurrence : ");

    for (i = 0; i < charFinder; i++) //terminate iterations at the amount of char found in line of string
        printf("%d, ", loc[i]);
    printf("\n");
    printf(PROMPT);
    }

}

//clear input buffer
void clearBuffer(void)
{
     while((getchar()) != '\n') ;
}

// Returns an integer value giving the number of times ch was found in *pStr.
int CharIsAt(char * pStr, char ch, int loc[], int mLoc)
{
    int count = 0, location = 0, max = mLoc - 1, index = 0;
    while (*pStr != '\0') 
    {
        if(*pStr == ch) //check if the character is the target char
        {
            count++;
            if (index <= max) loc[index] = location; //stores location
            index++;
        }
        location++;
        pStr++;
    }
    return count;
}

//get character we are searching for
int GetFirst(void) {
	int ch;
	ch = getchar();  // Get first character.
	clearBuffer();		  // Clear line to '\n'.
	return ch;
}

