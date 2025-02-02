char ** merge(char * s1[], int d1, char * s2[], int d2)
{
    char ** s3 = (char **) malloc(sizeof(char *) * (d1 + d2));
    int conta1 = 0, conta2 = 0;
    for(int i = 0; i < (d1 + d2); i++)
    {
        if(strcmp(s1[conta1], s2[conta2]) < 0)
        {
            s3[i] = (char *) malloc(sizeof(char) * (strlen(s1[conta1]) + 1));
            strcpy(s3[i], s1[conta1]);
            conta1++;
        }
        else if(strcmp(s1[conta1], s2[conta2]) > 0)
        {
            s3[i] = (char *) malloc(sizeof(char) * (strlen(s2[conta2]) + 1));
            strcpy(s3[i], s2[conta2]);
            conta2++;
        }
        else if(strcmp(s1[conta1], s2[conta2]) == 0)
        {
            s3[i] = (char *) malloc(sizeof(char) * (strlen(s1[conta1]) + 1));
            strcpy(s3[i], s1[conta1]);
            conta1++;
            i++;
            s3[i] = (char *) malloc(sizeof(char) * (strlen(s2[conta2]) + 1));
            strcpy(s3[i], s2[conta2]);
            conta2++;
        }
    }

    return s3;

}
