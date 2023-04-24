#include <stdio.h>

#define LEN 20

void CharPoint(const char * str);

int main(void)
{
    char * pstr, string[LEN];
    fputs("Enter a string here to pass to fuction as ptr: ", stdout);
    scanf("%s", string);
    pstr = string;
    CharPoint(pstr);

    return 0;
    
}

void CharPoint(const char * str)
{
    if(str)
    {
        fputs("Successfully accepted string ptr\n", stdout);
        while(*str != '\n' && *str != '\0' ) puts(str++) ;
    }
        
    else fputs("Failed\n", stdout);
}