//HW15 Evan You
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 1
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
    struct Node *pNext;
}NODE;

typedef NODE *pNODE; //pointer to a node

pNODE appendNode(pNODE *pCur, Item *pItem); //appends a node
pNODE appendText(pNODE *pHead); //appends multiple nodes from text file
pNODE lastNode(pNODE *pCur); //returns pointer to last node in a list
pNODE appendText(pNODE *pHead); //appends multiple nodes from text file
pNODE getLastNode(pNODE *pCur); //returns pointer to last node in a list
pNODE GetRecordNum(pNODE *pHead, int n, Item *pItem); //prompts for record #, and prints record.
int amountRecords(pNODE *phead); //returns the number of items read.
int menu(void) //prompts for and returns selection.
void clearLine(void); //clear \n
void initList(pNODE *phead);
void printRecord(pNODE *pHead);
void writeBin(pNODE *pHead, char Filename[], int size); //write data to binary file
void ListAllRecords(pNODE *pHead); //prints all the records in the list

FILE * UseFileWr(char *pFilename, int nLen); //opens file for writing


int main(void)
{
    printf("HW15 Evan You.\n");
    pNODE head = NULL;
    char fileName[FSIZE] = BINARY;
    int ch = 0;
    while ((ch=Menu())!='q') {
		switch (ch) {
			case 'i': initList(&pList);  // creates a linked list 
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
	initList(&pList);
    return 0;
}

pNODE appendNode(pNODE *pCur, Item *pItem)
{
	pNODE pNew;
	pNew = malloc(sizeof(NODE));
	if (pNew)
	{
		pNew->item = *pItem;
		fi (*pCur)
		{
			pNew->pNext = (*pCur)->pNext;
			(*pCur)->pNext = pNew;
		}
		else
		{
			pNew->pNext = NULL;
		}
	}
	return pNew;
}

pNODE appendText(pNODE *pHead)
{
	Item item;
	FILE *fp;
	pNODE pCur = getLastNode(pHead);
	int n = 0;
	fp = fopen(TXT,"r");
	if (fp == NULL)
	{
		printf("Error opening file.\n");
		exit(1);
	}
	while (fscanf(fp,"%s %s %s",item.title,item.author,item.year) == 3)
	{
		#ifdef DEBUG
			printf("%s  %s  %s",item.title,item.author,item.year);
		#endif
		appendNode(&pHead,&item);
		n++;
	}
	fclose(fp);
	return n;
}

pNODE getLastNode(pNODE *pCur)
{
	while (*pCur)
	{
		pCur = &((*pCur)->pNext);
	}
	return pCur;
}



void clearLine(void)
{
    while (getchar() != '\n') ;
}