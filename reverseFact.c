#include <stdio.h>
#include <limits.h>

int main(void){
    unsigned short nMax, i = 1;
    printf("Enter reverse factorial:");
    scanf("%hu", &nMax);
    while (nMax > 1)
    {
        nMax /= ++i;
    }
    
    printf("%hu\n", i);
    return 0;
    
//     for (i=1; nMax >= 1; i++)
//         nMax /= i;
//         printf("%hu\n",nMax);
        
//     printf("%hu\n", i);
}