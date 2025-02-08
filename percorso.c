#include <stdio.h>
#include <stdlib.h>

#define R 4
#define C 6



typedef  struct  { int deltai, deltaj; } Mossa;     
typedef  struct  nd { Mossa mv;  struct nd * next;  }  Step;      
typedef  Step * Percorso; 

int percorri(int m[][C], Percorso p);
int valida(int m[][C], Mossa mos, int i, int j);
int fuori_mappa(int m[][C], Mossa mos, int i, int j);
int trova_ostacolo(int m[][C], Mossa mos, int i, int j);

Percorso insTesta(Percorso p, int i, int j);



int main(void)
{
    int m[R][C] = {
        0, 1, 0, 1, 1, 0,
        0, 0, 1, 1, 0, 0,
        1, 0, 0, 0, 0, 1,
        1, 1, 0, 1, 0, 1
    };
    Percorso p = NULL;
    p = insTesta(p, 2, 0);
    p = insTesta(p, 0, 1);
    p = insTesta(p, 1, 0);
    p = insTesta(p, 0, 1);
    p = insTesta(p, 1, 0);
    printf("%d", percorri(m, p));
}


int percorri(int m[][C], Percorso p)
{
    int n_mosse = 0;
    int i = 0, j = 0;
    while(p != NULL)
    {
        if(valida(m, p->mv, i, j))
        {
            i += p->mv.deltai;
            j += p->mv.deltaj;
            n_mosse++;
            p = p->next;
        }
        else
        {
            printf("<%d, %d>\n", i, j);
            return n_mosse;
        }
    }
    printf("<%d, %d>\n", i, j);
    return n_mosse;
}

int valida(int m[][C], Mossa mos, int i, int j)
{
    return !fuori_mappa(m, mos, i, j) && !trova_ostacolo(m, mos, i, j); 
    //in realtà qui basterebbe trova_ostacolo perchè gia nel suo corpo controlla
    //se una mossa finisce fuori dalla mappa, per semplicità
    //Inoltre qui l'unico caso di ritorno valido è se entrambi le
    //funzioni ritornano 0
}


int fuori_mappa(int m[][C], Mossa mos, int i, int j)
{
    if( (i + mos.deltai) >= R || (j + mos.deltaj) >= C || (i + mos.deltai) < 0 || (j + mos.deltaj) < 0)
      return 1;
    return 0;
    //qui si potrebbero fare prima i calcoli poi confrontarli, sarebbe meglio
}

int trova_ostacolo(int m[][C], Mossa mos, int i, int j)
{
    if(!fuori_mappa(m, mos, i, j))
    {
        int ni = i + mos.deltai;
        int nj = j + mos.deltaj;
        int step = 0;
        if(mos.deltai == 0 && mos.deltaj == 0)
          return 0;
        if(mos.deltai != 0)
        {
            if(mos.deltai > 0)
              step = 1;
            else
              step = -1;
            for(int x = i; x != ni; x += step)
              if(m[x][j] == 1)
                return 1;
        }
        else
        {
            if(mos.deltaj > 0)
              step = 1;
            else
              step = -1;
            for(int x = j; x != nj; x += step)
              if(m[i][x] == 1)
                return 1;            
        }
        return 0;
    }
    else
      return 1; //ritorna 1 anche se non trova ostacolo ma esce dalla mappa
}

Percorso insTesta(Percorso p, int i, int j)
{
    Percorso punt = (Percorso) malloc(sizeof(Step));
    Mossa m;
    m.deltai = i;
    m.deltaj = j;
    punt->mv = m;
    punt->next = p;
    return punt;
}



