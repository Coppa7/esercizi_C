#include <stdio.h>

char min_ch(char * s);

char min(char a, char b);


int main(void)
{

    printf("%c", min_ch("MELO"));

    return 0;
}

char min(char a, char b)
{
    if(a < b)
      return a;
    else
      return b;
}




char min_ch(char * s)
{
    if(*s == NULL)
      return '\0';

    char cur = *s;
    
    if(*(s+1) == NULL)
      return cur;

    return min(cur, min_ch(s+1));
}
