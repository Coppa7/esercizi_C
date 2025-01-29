#include <stdio.h>

typedef  struct  nd {   int val;  struct nd * next;  }  Nodo; 

typedef  Nodo * Lista; 

int diff_piu_freq(Lista lis);
Lista insTesta(Lista lis, int n);

int main(void)
{
    Lista lis = NULL;

    lis = insTesta(lis, 18);
    lis = insTesta(lis, 12);
    lis = insTesta(lis, 7);
    lis = insTesta(lis, 3);
    lis = insTesta(lis, 1);



    printf("%d", diff_piu_freq(lis));

    return 0;
}

int diff_piu_freq(Lista lis)
{
    if (lis != NULL && lis->next != NULL)
    {
        int min = 0, max = 0;
        int max_occ = 0;
        min = lis->val;
        Lista punt = lis;
        while (punt != NULL && punt->next != NULL)
            punt = punt->next;

        max = punt->val;

        int *occ = (int *)calloc(max - min + 1, sizeof(int));

        int diff = 0;

        while (lis != NULL)  //non c'è bisogno del controllo lis->next != NULL perchè già c'è all'inizio
        {
            punt = lis->next;
            while(punt != NULL)
            {
                diff = punt->val - lis->val;
                occ[diff]++;
                punt = punt->next;
            }
            lis = lis->next;
        }

        max_occ = occ[0];   //esiste sempre
        int num = 0;

        for(int i = 0; i < (max - min); i++)
            if(occ[i] > max_occ)
            {  
                max_occ = occ[i];
                num = i;
            }

        free(occ);

        return num;
    }
    else
        return -1;
}

Lista insTesta(Lista lis, int n)
{
    Lista punt = (Lista) malloc(sizeof(Nodo));
    punt->val = n;
    punt->next = lis;
    return punt;
}
