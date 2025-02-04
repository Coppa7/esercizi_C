#include <stdio.h>

#define R 3
#define C 4

int aristo(int m[][C]);
int maxRigaPos(int m[][C], int r);

int main(void)
{
    int m[R][C] = {
        11, 3, 8, 2,
        12, 15, 22, 3,
        3, 3, 13, 16
    };
    printf("%d", aristo(m));
}



int aristo(int m[][C])
{
    int pos[R]; //vettori posizione dei massimi delle righe;
    int conta = 0; //contatore vettore pos
    for(int i = 0; i < R; i++){
        pos[conta] = maxRigaPos(m, i);
        //printf("%d ", pos[conta]);
        conta++;
    }

    for(int i = 0; i < conta - 1; i++)
    {
        //printf("%d %d", pos[i], pos[i + 1]);
        if(pos[i] >= pos[i + 1])
          return 0;
    }
    return 1;
}

int maxRigaPos(int m[][C], int r)
{
    int max = m[r][0];
    int pos_max = 0;
    int i = 0;
    for(i = 1; i < C; i++)
        if(m[r][i] > max)
        {
            max = m[r][i];
            pos_max = i;
        }

    return pos_max;
}
