#include <stdio.h>

typedef  struct  nd {   int val;  struct nd * next;  }  Node;
typedef  Node * List; 

List centra(List lis);
List insTesta(List lis, int n);
int lenLista(List lis);
void visLista(List lis);

int main(void)
{

    List lis = NULL;
    lis = insTesta(lis, 3);
    lis = insTesta(lis, 4);
    lis = insTesta(lis, 5);
    lis = insTesta(lis, 6);
    //lis = insTesta(lis, 7);   cambia la lista d'esempio da pari a dispari

    visLista(lis);

    centra(lis);

    visLista(lis); 

    return 0;
}

List centra(List lis)
{
    int len = lenLista(lis);
    List lis_copia = lis;
    if (lis != NULL && lis->next != NULL)
    {
        if ((len % 2) == 0)
        {
            for (int i = 0; i < (len / 2 - 1); i++) // arriva al nodo "centrale-sinistro"
                lis_copia = lis_copia->next;
            List punt = (List)malloc(sizeof(Node));
            punt->val = 0;
            punt->next = lis_copia->next;
            lis_copia->next = punt;
        }
        else
        {
            for (int i = 0; i < (len / 2); i++) // arriva al nodo centrale
                lis_copia = lis_copia->next;
            lis_copia->val = 0;
        }
    }
    if(lis == NULL)
      lis = insTesta(lis, 0);
    if(lis->next == NULL)
      lis->val = 0;
    return lis;
}

List insTesta(List lis, int n)
{
    List punt;
    punt = (List) malloc(sizeof(Node));
    punt->val = n;
    punt->next = lis;
    return punt;
}

int lenLista(List lis)
{
    int len = 0;
    while(lis != NULL)
    {
        len++;
        lis = lis->next;
    }
    return len;
}

void visLista(List lis)
{
    if (lis == NULL) {
        printf("La lista è vuota\n");
        return;
    }

    while (lis->next != NULL) {
        printf("%d-->", lis->val);
        lis = lis->next;
    }
    printf("%d\n", lis->val);
}
