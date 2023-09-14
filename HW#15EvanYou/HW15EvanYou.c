//HW15 Evan You
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define TSIZE 100 //title string
#define ASIZE 50  // author string
#define YSIZE 7   // year string
#define FSIZE 50  // Size for the filename
#define TXT "HW15Data.txt" // Text input filename.
#define BINARY "HW15Binary.xxx" // Binary filename.

struct Book 
{
    char title[TSIZE], author[ASIZE], year[YSIZE];
};
typedef struct Book Item;
typedef struct Node 
{
    Item item; 
    struct Node *pnext;
}NODE;

typedef NODE *PNODE; //pointer to a node

PNODE appendNode(PNODE *pCur, Item *pItem); //appends a node
PNODE appendText(PNODE *pHead); //
PNODE lastNode(PNODE *pCur);
int amountRecords(PNODE *phead); //returns the number of items read. 
int menu(void);
void clearLine(void); //clear \n
void initalize(PNODE *phead);
void printRecord(PNODE *pHead);
void writeBin(PNODE *pHead, char Filename[], int size); //write data to binary file


int main(void)
{
    printf("HW15 Evan You.\n");
    PNODE plist = NULL;
    char fileName[FSIZE] = BINARY;
    int ch = 0;
    while ((ch=Menu())!='q') {
		switch (ch) {
			case 'i': initalize(&pList);  // creates a linked list 
						break;
			case 'a': appendText(&pList);  // Sets pList if it was NULL,
						break;
			case 'p': printRecord(&pList);  // Prompts for record #, and prints record.
						break;
			case 'l': ListAllRecords(&pList);  // Prints all the records in the list.
						break;
			case 'w': writeBin(&pList,fileName,FSIZE);	// Writes data to a binary file.	 
		}
	}


    return 0;
}




void clearLine(void)
{
    while (getchar() != '\n') ;
}