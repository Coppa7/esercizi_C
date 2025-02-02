#include <stdio.h>

#define R 3
#define C 4

typedef struct{
    int num;
    int * r;
    int * c;
} minimiMat;

minimiMat minRC(float g[][C]);

int is_RC(float g[][C], int i, int j);

int main(void)
{

    FILE * fp = fopen("griglia.txt", "r"); //fopen(argv[1], "r");
    int n = 4; //n = atoi(argv[2]);
    float val = 0.0;
    int i = 0, j = 0;
    char c;

    if(fp != NULL)
    {
        float m[R][C];
        while(fscanf(fp, "%f%c", &val, &c) == 2)
        {
            m[i][j] = val;
            if(c == '\n')
            {
                i++;
                j = 0;
            }
            j++;    
        }

        minimiMat m1 = minRC(m);
        printf("Numero di valori: %d\n", m1.num);
        if(n <= m1.num)
          for(int i = 0; i < n; i++)
            printf("<%d, %d>", m1.r[i], m1.c[i]);
    }

    return 0;
}

minimiMat minRC(float g[][C])
{
    int n_valori = 0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(is_RC(g, i, j))
                n_valori++;

    minimiMat m1;
    m1.num = n_valori;
    m1.r = (int *) calloc(sizeof(int), n_valori);
    m1.c = (int *) calloc(sizeof(int), n_valori);
    int conta = 0; //contatore interno dei vettori delle coordinate

    for(int i = 0; i < R; i++)
      for(int j = 0; j < C; j++)
        if(is_RC(g, i, j))
        {
            m1.r[conta] = i;
            m1.c[conta] = j;
            conta++;
        }

    return m1;
}

int is_RC(float g[][C], int i, int j)
{
    int minimo_riga = 1, minimo_colonna = 1; //booleani
    //prima controllo le righe;
    for(int x = 0; x < R; x++)
        if(x != i && g[x][j] < g[i][j])
          minimo_riga = 0;
    //poi le colonne
    for(int x = 0; x < C; x++)
        if(x != j && g[i][x] < g[i][j])
          minimo_colonna = 0;

    return (minimo_riga && minimo_colonna);
}



