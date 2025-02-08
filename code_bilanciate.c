#include <stdio.h>

typedef  struct  nd {   int val;  struct nd * next;  }  Nodo;          
typedef  Nodo * List; 

typedef struct{
    int pari;
    int dispari;
} par_lista;

int contaCodeBilanciate(List lis);
par_lista paritaLista(List lis);
List insTesta(List lis, int n);


int main(void)
{

    List lis = NULL;
    lis = insTesta(lis, 3);
    lis = insTesta(lis, 3);
    lis = insTesta(lis, 6);
    lis = insTesta(lis, 2);
    lis = insTesta(lis, 1);
    lis = insTesta(lis, 4);
    lis = insTesta(lis, 7);


    printf("%d", contaCodeBilanciate(lis));
    

    return 0;
}



int contaCodeBilanciate(List lis)
{
    if(lis == NULL)
      return 0;
    
    par_lista par1;
    par1 = paritaLista(lis);
    if(par1.pari == par1.dispari)
      return 1 + contaCodeBilanciate(lis->next);
    return contaCodeBilanciate(lis->next);
}

par_lista paritaLista(List lis)  //non totalmente efficiente: analizza per ogni nodo i nodi successivi
{
    par_lista par1;
    par1.pari = 0;
    par1.dispari = 0;
    while(lis != NULL)
    {
        if(lis->val % 2 == 0)
          par1.pari++;
        else
          par1.dispari++;
        lis = lis->next;
    }
    return par1;
}

List insTesta(List lis, int n)
{
    List punt = (List) malloc(sizeof(Nodo));
    punt->val = n;
    punt->next = lis;
    return punt;
}


