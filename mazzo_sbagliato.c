#include <stdio.h>

#define V 13
#define S 4

int main(int argc, char * argv)
{
    if (argc > 1)
    {
        FILE *fp = fopen(argv[1], "r"); // legge nome file da linea di comando, inoltre nel file i numeri sono dati
        char c;                         // nella forma (v, s), senza caratteri intermedi. Il file inoltre è ben formato
        int val = 0, seme = 0;
        if (fp != NULL)
        {
            int mazzo[S][V] = {0};
            while (fgetc(fp)) // libera prima parentesi
            {
                fscanf(fp, "%d", &val);         // ritira valore
                fgetc(fp);                  // rimuovi virgola
                fscanf(fp, "%d", &seme);        // ritira seme
                mazzo[seme - 1][val - 1]++; // aggiungo il meno 1 perche i semi vanno da 1-4 e i valori da 1-13
            }
            if (mazzoSbagliato(mazzo))
                printf("KO");
            else
                printf("OK");
        }
        else
        {
            printf("KO");
            return -1;
        }
        return 0;
    }
    else
      return -2;
}

int mazzoSbagliato(int m[][V])
{
    int bool_Pieno = 1;
    for(int i = 0; i < S; i++)
      for(int j = 0; j < V; j++)
        if(m[i][j] == 0 || m[i][j] > 1)
          return 1;
    
    return 0;
}
