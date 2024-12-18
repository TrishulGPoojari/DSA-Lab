# include <stdio.h>
# include <string.h> 
char T[40], P[20], REP[20], FIN[100]; 
int slen(char *);
void replace();

int main() {
    printf("Enter a string: ");
    scanf("%39[^\n]", T);
    getchar();
    printf("Enter a pattern:");
    scanf("%19[^\n]", P);
    getchar();
    printf("Enter a replacement pattern: ");
    scanf("%19[^\n]", REP);
    getchar();
    replace();
    printf("Output %s\n",FIN);
}

int slen(char *s)
{
    int len=0;
    for(;s[len]!='\0';len++);
    return len;
}
void replace()
{
    int k=0,q=0,s=slen(T),r=slen(P),i,j; //k is itereate over old string and q for new string 
    //i and j is too loop over the patterns 
    while(k<s)
    {
        for(i=0;i<r;i++)
        {
        if (P[i] != T[k+i])
            break;
        }
        if (i==r)
        {
            for(j=0;j<strlen(REP);j++)
            FIN[q++] = REP[j];
            k = k + r;
        }
        else
            FIN[q++] = T[k++];
    }
    FIN[q]='\0'; //add NULL character at last 
}