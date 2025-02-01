#include <stdio.h>

int shrink(FILE * fin, FILE * fout);

int main(void)
{

    FILE * fin = fopen("input.txt", "r");
    /*esempio di file di input: 
    abdc(babbcde)f(zbndghertttth)h(abcdea)upn(d)wd.*/
    FILE * fout = fopen("output.txt", "w");
    /*output esempio:
    abdcbfthaupndwd  
    è stato ottenuto sostituendo ad ogni sottosequenza 
    data dalle parentesi il carattere più frequente della sottosequenza*/

    if(fin != NULL && fout != NULL)
    {
        printf("%d", shrink(fin, fout));
    }

    return 0;
}

int shrink(FILE * fin, FILE * fout)
{
    int alfabeto[26] = {0};  //vettore di presenza lettere dell'alfabeto in ogni sottosequenza
    char c;
    int sotto_sequenze = 0;
    int max;
    char max_char;
    while((c = fgetc(fin)) != '.')
    {
        if(c == '(')
        {
            while( (c = fgetc(fin)) != ')')
                alfabeto[c - 'a']++;

            max = alfabeto[0];
            max_char = 'a';

            for(int i = 0; i < 26; i++)
                if(alfabeto[i] > max)
                {
                    max = alfabeto[i];
                    max_char = i + 'a';
                }

            fputc(max_char, fout);
            sotto_sequenze++;
            max = 0;
            for(int i = 0; i < 26; i++)
              alfabeto[i] = 0;
        }
        else
          fputc(c, fout);
    }

    return sotto_sequenze;

}

