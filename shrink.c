#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * shrink(char * s);

int main(void)
{
    char * s = "Mar di Marmara";           //Stringa di esempio
    char * s_new;
    if((s_new = shrink(s)) != NULL)
    {
       printf("%s", s_new);
       free(s_new);
    }
    return 0;
}

char * shrink(char * s)
{
    int lun = strlen(s);
    if (lun > 0)
    {
        int ascii[256] = {0};                        //vettore che conta la presenza dei caratteri ascii nella stringa
        int conta_unici = 0;
        int conta_newstring = 0;
        for (int i = 0; i < strlen(s); i++)
            if (ascii[s[i]] != 1)
            {
                ascii[s[i]]++;
                conta_unici++;
            }

        char * new_s = (char *)malloc(sizeof(char) * (conta_unici + 1));

        for (int i = 0; i < strlen(s); i++)
        {
            if (ascii[s[i]] == 1)
            {
                new_s[conta_newstring] = s[i];
                ascii[s[i]]++;                          //aumento da 1 a 2 per segnalare che il carattere è stato usato
                conta_newstring++; 
            }
        }
        new_s[conta_unici] = '\0';
        return new_s;
    }

    return NULL;


    
}
