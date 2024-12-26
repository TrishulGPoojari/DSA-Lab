#include <stdio.h>     //recurrsive function call
void tower(int n,char s,char i,char d)
{
    if(n==1)   // only one disk is present in the stand 
        printf("Move disc %d from %c to %c\n",n,s,d);
    else{
                               // make use of printf("hello\n"); to understand the flow
        tower(n-1,s,d,i);      //the disk is moved from source to intermediate (A to B) and one disk it left on source
     printf("Move disc %dfrom %c to %c\n",n,s,d); //outside else block 
     tower(n-1,i,s,d);          //the disk is moved from intermediate to destination (B to C) and one disk is left on intermediate
    }
    
}


int main()
{
    int n;
    printf("Enter no of disc:\n");
    scanf("%d",&n);
    tower(n,'A','B','C');   // A B C refers to the stands
}
