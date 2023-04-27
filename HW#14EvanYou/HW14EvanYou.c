//Evan You HW#14

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEN 50
#define ELEMENTS 5

typedef struct Name
{
    char first[LEN];
    char last[LEN];
}Name;

struct Person
{
    int SSN;
    Name Full;
};

void printStruct(struct Person *people);
char * getFirstName(char (*names)[LEN], int n);
char * getLastName(char (*names)[LEN], int n);
int generateSSN();

int main(void)
{
    fputs("Evan You HW14\n", stdout);
    srand(time(NULL));

    //create char 2d array of first and last names
    char Firstnames[][LEN] = {"Adam", "Alexander", "Bill", "Bob", "Carrie" , "Steven", "Ken", "Evan", "Mason", "Preston"};
    char Lastnames[][LEN] = {"Smith", "Johnson", "Anderson", "Miller", "Davidson" , "Thomas", "Taylor", "Young", "Jones", "Allen"};

    //determine number of elements in array of names
    int f = sizeof(Firstnames)/sizeof(Firstnames[0]);
    int l = sizeof(Lastnames)/sizeof(Lastnames[0]);


    struct Person people[ELEMENTS];     //array of structure person
    for (int i=0; i<ELEMENTS; i++)
    {
        people[i].SSN = generateSSN();
        strcpy(people[i].Full.first, getFirstName(Firstnames, f));
        strcpy(people[i].Full.last, getLastName(Lastnames, l));
        printStruct(&people[i]);  
    }

    return 0;
}

//prints out the structure
void printStruct(struct Person *people)
{
    fprintf(stdout, "%9d -- %s, %s\n", people->SSN, people->Full.last, people->Full.first);
}

char * getFirstName(char (*names)[LEN], int n)
{
    return  names[rand() %n];
}

char * getLastName(char (*names)[LEN], int n)
{
    return  names[rand() %n];
}

//generates a random SSN
int generateSSN()
{
    int upper = 999999999;
    int lower = 100000000;
    return rand() % (upper - lower + 1 ) + lower;
}