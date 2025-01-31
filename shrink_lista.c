#include <stdio.h>
#include <string.h>

typedef  struct  nd {   char * word;  struct nd * next;  }  Nodo; 
typedef  Nodo * Lista; 

char * shrink(char * str, char * mask);
char * insTesta(Lista lis, char * s);
Lista riduci(Lista x, char * mask);
void visLista(Lista lis);

int main(void)
{
    //printf("%s", shrink("ABCDE", "10"));

    Lista lis = NULL;
    lis = insTesta(lis, "TROGOLO");
    lis = insTesta(lis, "ZANGOLA");
    lis = insTesta(lis, "ZIO");
    lis = insTesta(lis, "NEGOZIO");
    lis = insTesta(lis, "OZIO");
    visLista(lis);
    lis = riduci(lis, "01001");
    visLista(lis);
    return 0;
}

char * shrink(char * str, char * mask)
{
    int len_str = strlen(str), len_mask = strlen(mask);
    int lun_new = 0;
    for(int i = 0; i < len_mask; i++)
        if(mask[i] == '1')
          lun_new++;

    char * str_new = (char * ) malloc(sizeof(char) * (lun_new + 1));
    int j = 0;
    if(len_mask >= len_str)
    {
        for(int i = 0; i < len_str; i++)
          if(mask[i] == '1')
          {
             str_new[j] = str[i];
             j++;
          }
    }
    else
    {
        int i = 0;
        for(i; i < len_mask; i++)
        {
            if(mask[i] == '1')
            {
                str_new[j] = str[i];
                j++;
            }
        }
        while (str[i] != '\0')
        {
            str_new[j] = str[i];
            j++;
            i++;
        }
    }
    str_new[j] = '\0';
    return str_new;
}

char * insTesta(Lista lis, char * s)
{
    Lista punt = (Lista) malloc(sizeof(Nodo));
    punt->word = s;
    punt->next = lis;
    return punt;
}

Lista riduci(Lista x, char * mask)
{
    if(x != NULL)
    {
        Lista punt = x;
        Lista prec = NULL;
        Lista cur = NULL;
        while (punt != NULL)
        {
            if (strlen(punt->word) != 0 && shrink(punt->word, mask)[0] != 'Z')
            {
                punt->word = shrink(punt->word, mask);
                prec = punt;
                punt = punt->next;
            }
            else
            {
                if(prec == NULL)
                {
                    x = punt->next;
                    free(punt);
                    punt = x;
                }
                else
                {
                    cur = punt;
                    prec->next = punt->next;
                    punt = prec->next;
                    free(cur);
                    prec = punt;
                }
            }
        }
        return x;
    }
    return NULL;
}




void visLista(Lista lis)
{
    while(lis->next != NULL)
    {
        printf("%s --> ", lis->word);
        lis = lis->next;
    }
    printf("%s\n", lis->word);

}

