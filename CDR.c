#include <stdio.h>
#include <limits.h>

typedef  struct {  int quanti, min, max;  }  CDR; 

CDR * analizza(int k);

int main(void)
{
    int k;
    scanf("%d", &k);
    CDR * vet = analizza(k);
    free(vet);
    return 0;
}

CDR * analizza(int k)
{
    CDR * vet = (CDR * ) malloc(sizeof(CDR) * k);  //Vettore di k classi di resto 
    for(int i = 0; i < k; i++)
    {
        (vet[i]).quanti = 0;
        (vet[i]).max = -__INT_MAX__;
        (vet[i]).min =  __INT_MAX__;
    }
    int n;
    scanf("%d", &n);
    int resto = 0;
    while(n != 0)
    {
        if (n > 0)
            resto = n % k;
        else
            resto = (-n) % k;
        (vet[resto]).quanti++;
        if (n > (vet[resto].max))       
            (vet[resto]).max = n;
        if (n < (vet[resto].min))
            (vet[resto]).min = n;
        scanf("%d", &n);
    }
}
