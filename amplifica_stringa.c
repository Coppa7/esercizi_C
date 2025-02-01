#include <stdio.h>
#include <string.h>

char * amplify(char * s, int * m);

int main(void)
{

    int v[5] = {3, 0, 0, 2, 4};

    printf("%s", amplify("ABCDE", v));

    return 0;
}

char * amplify(char * s, int * m)
{
    //supposto vero che la lunghezza di s sia uguale al numero di interi di m
    int len_new = 0;
    int len_s = strlen(s);
    for(int i = 0; i < len_s; i++)
      len_new += m[i];

    char * new_s = (char * ) malloc(sizeof(char) * (len_new + 1));

    int j = 0; //contatore interno della stringa;

    for(int i = 0; i < len_s; i++)
        for(int x = 0; x < m[i]; x++)
        {
            new_s[j] = s[i];
            j++;
        }

    new_s[j] = '\0';

    return new_s;
}
