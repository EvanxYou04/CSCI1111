#include <stdio.h>
#include <stdlib.h>
#define NAMESIZE 20
#define MAXNODE 5

typedef struct stItem
{
    char name[NAMESIZE];
}Item;
struct stNode
{
    Item item; 
    struct stNode * next;
};
typedef struct stNode NODE;
typedef NODE * PNODE;

void EmptyList(PNODE * free);


int main(void)
{
    PNODE curNode;
    int i;
    PNODE ListHead = (PNODE) malloc(sizeof(NODE));
    if(ListHead) ListHead->next = NULL;
    for (i=0, curNode = ListHead; i<MAXNODE; i++)
    {
        curNode->next = (PNODE) malloc(sizeof(NODE));
        if(curNode->next != NULL)
        {
            curNode = curNode->next;
            curNode->next = NULL;
        }
    }
   
    EmptyList(&ListHead);
    return 0;
}

void EmptyList(PNODE * freeNode)
{
    PNODE current = *freeNode, temp;
    while(current != NULL)
    {
        temp = current->next;
        free(current);
        printf("freed a node.\n");
        current->next = temp;
    }
}