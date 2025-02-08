#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN_STR 20

typedef struct nd{
    char cod[MAX_LEN_STR + 1];
    int cit;
    struct nd * next;
} Nodo;

typedef Nodo * Lista;

typedef struct{
    char nome[MAX_LEN_STR + 1];
    char cognome[MAX_LEN_STR + 1];
    int h_idx;
} H_Idx;


H_Idx h_index(FILE * fp);
Lista insOrdinato(Lista lis, int ci, char * cd);
int conta_Idx(Lista lis);

int main(int argc, char * argv[])
{
    if(argc > -1)  //argc > 1
    {
        FILE * fp = fopen("h_index_file.txt", "r");  //FILE * fp = fopen(argv[1], "r");

        if(fp != NULL)
        {
            H_Idx idx1 = h_index(fp);
            printf("(%s %s) --> h_idx = %d", idx1.nome, idx1.cognome, idx1.h_idx);
            return 0;
        }
        else
          return -1;
    }
    else
      return -2;
}

H_Idx h_index(FILE * fp)
{
    char nom[MAX_LEN_STR + 1], cog[MAX_LEN_STR + 1], codice[MAX_LEN_STR + 1];
    int citazioni = 0; 
    fscanf(fp, "%s%s", nom, cog);
    H_Idx index1;
    strcpy(index1.nome, nom);
    strcpy(index1.cognome, cog);
    Lista lis = NULL;    
    while(fscanf(fp, "%s%d", codice, &citazioni) == 2)
        lis = insOrdinato(lis, citazioni, codice);

    index1.h_idx = conta_Idx(lis);

    return index1;
}

Lista insOrdinato(Lista lis, int ci, char * cd)
{
    if(lis == NULL || lis->cit <= ci)
    {
        Lista punt = (Lista) malloc(sizeof(Nodo));  
        punt->cit = ci;
        strcpy(punt->cod, cd);
        punt->next = lis;
        return punt;
    }
    lis->next = insOrdinato(lis->next, ci, cd);
    return lis;
}

int conta_Idx(Lista lis)
{
    int conta = 0;
    int pos = 1; //per sicurezza uso 2 variabili in quanto la posizione non inizia da 0
    while(lis != NULL && pos <= lis->cit)
    {
        conta++;
        pos++;
        lis = lis->next;
    }
    return conta;
}

