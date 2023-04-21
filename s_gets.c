//improved version of get_s()
#include <stdio.h>

#define LEN 10

char * s_gets(char * st, int n);    //prototype

int main(void){
    char words[LEN];
    puts(s_gets(words, LEN));
    return 0;
}


//improved version of get_s()
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * pc = st;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while (*pc != '\0' && *pc != '\n') pc++;
        if (*pc == '\n')
            *pc = '\0';
        else
            while(getchar() != '\n') ;  
    }
    return ret_val;
}