#include <stdio.h>

typedef  struct  nd {   char c;   struct nd * next;  }  Nodo;    
typedef  Nodo * Lista;  

char * zip(Lista lis);
int contaNodi(Lista lis);
int contaOccorrenze(Lista lis);
void printaLista(Lista lis);
Lista insTesta(Lista lis, char ch);


int main(void)
{

    Lista lis = NULL;
    lis = insTesta(lis, '!');
    lis = insTesta(lis, '!');
    lis = insTesta(lis, '!');
    lis = insTesta(lis, 'e');
    lis = insTesta(lis, 'r');
    lis = insTesta(lis, 'p');
    lis = insTesta(lis, 'm');
    lis = insTesta(lis, 'm');
    lis = insTesta(lis, 'm');
    lis = insTesta(lis, 'm');
    lis = insTesta(lis, 'e');
    lis = insTesta(lis, 's');
    lis = insTesta(lis, 'A');
    lis = insTesta(lis, 'S');
    lis = insTesta(lis, 'S');
    lis = insTesta(lis, 'A');
    lis = insTesta(lis, 'B');
    lis = insTesta(lis, 'B');
    lis = insTesta(lis, 'B');
    lis = insTesta(lis, 'A');
    lis = insTesta(lis, 'S');

    printaLista(lis);

    printf("%s", zip(lis));

    //SAB3AS2Asem4pre!3  Output desiderato
    //SAB3AS2Asem4pre!3  Output ottenuto




    return 0;
}

int contaNodi(Lista lis)
{
    int conta = 0;
    while(lis != NULL)
    {
        conta++;
        lis = lis->next;
    }
    return conta;
}

int contaOccorrenze(Lista lis)
{
    int occ = 0;
    char ch = lis->c;
    while(lis != NULL && lis->c == ch)
    {
        occ++;
        lis = lis->next;
    }
    return occ;
}



char * zip(Lista lis)
{
    int len_str = contaNodi(lis);
    char * str = (char *) malloc(sizeof(char) * (len_str + 1)); //Alloco una stringa il base alla sua massima lunghezza, ma non ideale
    int occ = 0;
    int conta = 0; //contatore str
    while(lis != NULL)
    {
        occ = contaOccorrenze(lis);
        if(occ == 1)
        {
            str[conta] = lis->c;
            conta++;
            lis = lis->next;
        }
        else if(occ > 1)  //Per sicurezza deve essere sicuro maggiore di 1 se non 1
        {
            str[conta] = lis->c;
            conta++;
            str[conta] = occ + '0';
            conta++;
            for(int i = 0; i < occ; i++)
              lis = lis->next;
        }
    }
    str[conta] = '\0';
    return str;
}

void printaLista(Lista lis)
{
    while(lis != NULL && lis->next != NULL)
    {
        printf("%c-->", lis->c);
        lis = lis->next;
    }
    printf("%c\n", lis->c);
}

Lista insTesta(Lista lis, char ch)
{
    Lista punt = (Lista) malloc(sizeof(Nodo));
    punt->c = ch;
    punt->next = lis;
    return punt;
}



