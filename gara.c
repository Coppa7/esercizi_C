#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_STR 25

typedef struct nd{
    char cognome[MAX_LEN_STR+1];
    char nazione[MAX_LEN_STR+1];
    int partecipanti;
    struct nd * next;
} Nodo;

typedef Nodo * Lista;

Lista provenienze(FILE * fp);
Lista insLista(Lista lis, char * c, char * n);
void printLista(Lista lis);
Lista insCoda(Lista lis, char * c, char * n);

int main(void)
{

    FILE * fp = fopen("nazioni.txt", "r");

    if(fp != NULL)
    {
        Lista lis = NULL;
        lis = provenienze(fp);
        printLista(lis);
    }
    

    return 0;
}

Lista provenienze(FILE * fp)
{
    char cog[MAX_LEN_STR + 1];
    char naz[MAX_LEN_STR + 1];
    Lista lis = NULL;
    while(fscanf(fp, "%s%s", cog, naz) == 2)
    {
        lis = insLista(lis, cog, naz);
    }
    return lis;
}

Lista insLista(Lista lis, char * c, char * n)
{
    Lista head = lis;

    while(lis != NULL && strcmp(lis->nazione, n) != 0)
      lis = lis->next;

    if(lis == NULL)
    {
        head = insCoda(head, c, n);
        lis = head;
        while(lis != NULL && lis->next != NULL)
          lis = lis->next;
        lis->partecipanti = 1;
    }
    else
      lis->partecipanti++;

    return head;

}

Lista insCoda(Lista lis, char * c, char * n)
{
    Lista punt;
    if(lis == NULL)
    {
        punt = (Lista) malloc(sizeof(Nodo));
        strcpy(punt->cognome, c);
        strcpy(punt->nazione, n);
        punt->next = lis;
        return punt;
    }

    lis->next = insCoda(lis->next, c, n);

    return lis;
}


void printLista(Lista lis)
{
    while(lis != NULL)
    {
        printf("<%s, %d>", lis->nazione, lis->partecipanti);
        lis = lis->next;
    }
}


