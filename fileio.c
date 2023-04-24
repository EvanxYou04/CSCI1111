#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE * fptr; 
    char *str1 = "Hello my name is evan\n";
    char *str2 = "Practicing file i/o.\n";
    double arr[3] = {3.22,4.232,12.22};
    int ch;
    if ((fptr = fopen("text.txt" , "w")))
    {
        fputs(str1, fptr);
        fputs(str2, fptr);
        fwrite(arr,sizeof(double), 3,fptr);
        fclose(fptr);
        if ((fptr = fopen("text.txt" , "r")))
        {
            fputs("\nUsing text mode to read the file.\n", stdout);
            while ((ch = fgetc(fptr)) != EOF) putchar(ch);
            fclose(fptr);
        }
        if ((fptr = fopen("text.txt" , "rb")))
        {
            fputs("\n using binary mode to read the file.\n", stdout);
            while ((ch= fgetc(fptr)) != EOF) putchar(ch);
            fclose(fptr);
        }
    }

    return 0;
    
}