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
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while (st[i] != '\0' && st[i] != '\n')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n') ;  
    }
    return ret_val;
}