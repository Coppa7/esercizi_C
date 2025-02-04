#include <stdio.h>
#include <string.h>

typedef struct is { long int codicepersona;  
char policode[10];  
struct is * next; } Iscritto; 
typedef Iscritto * Lista; 

int compatibili(char * a, char * b);
int checkComplementari(char * a, char * b);
int checkSpeculari(char * a, char * b);
Lista insTesta(Lista lis, long int cd, char pcd[]);
Lista foreveralone(Lista lis);


int main(void)
{
    return 0;
}

int compatibili(char * a, char * b)
{
    return checkComplementari(a, b) || checkSpeculari(a, b);
}

int checkComplementari(char * a, char * b)
{
    if(strlen(a) == strlen(b))
    {
        int len = strlen(a);
        for(int i = 0; i < len; i++)
            if((a[i] == 'S' && b[i] == 'S') || (a[i] == 'D' && b[i] == 'D'))
              return 0;
        return 1;
    }
    return 0;
}

int checkSpeculari(char * a, char * b)
{
    if(strlen(a) == strlen(b))
    {
        int len = strlen(a);
        for(int i = 0; i < len / 2; i++)
        {
            if(a[i] != b[len - i - 1])
              return 0;
        }
        return 1;
    }
    return 0;
}

Lista insTesta(Lista lis, long int cd, char pcd[])
{
    Lista punt = (Lista) malloc(sizeof(Iscritto));
    punt->codicepersona = cd;
    strcpy(punt->policode, pcd);
    punt->next = lis;
    return punt;
}


Lista foreveralone(Lista lis)
{
    Lista alone = NULL;
    Lista cur;
    int bool_compatibile = 0;
    if(lis != NULL && lis->next != NULL)  //non ha senso se ho una lista vuota o di 1 sola persona
    {
        while(lis != NULL)
        {
            cur = lis;
            while(cur != NULL && !bool_compatibile)
            {
                cur = cur->next;
                if(cur != NULL &&  compatibili(lis->policode, cur->policode))
                  bool_compatibile = 1;
            }
            if(!bool_compatibile)
              alone = insTesta(alone, lis->codicepersona, lis->policode);
            bool_compatibile = 0;
            lis = lis->next;
        }
        return alone;
    }
    else
      return NULL;
}

