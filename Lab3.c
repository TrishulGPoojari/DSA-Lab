#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#define MAX_ELE 5

void push();
void pop();
void display();
void palin();
void status();

int top=-1; 
int s[MAX_ELE];

int main()
{
    int ch,n;
    printf("****Stack Operations****");
    for(;;) {
        printf("\n1:push\n2:pop\n3:display\n4:Status\n5:Palindrome\n6:Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Number of elements you want to add:\n"); scanf("%d",&n);
                    for(int i=0;i<n;i++)
                    push(); 
                    break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: status(); break;
            case 5: palin(); break;
            default: exit(0);
        }
    }
}
void status()
{
    int used;
    if (top==-1)
    used = 0;
    else
    used = top+1;
    printf("%d locations of the stack are used up\n", used);
    printf("%d locations of the stack are free\n", MAX_ELE - used);
}
void display()
{
    int i;
    if( (top) == -1)
    printf("Stack is empty\n");
    else
    {
    printf("Stack elements are\n");
    for(i=(top); i>=0; i--)
        printf("%d ",s[i]);
    }
}
void push()
{
    int ele;
    if( (top)==MAX_ELE-1)
    { printf("stack overflow\n"); return; }
    printf("enter the element\n"); scanf("%d",&ele);
    s[++top]=ele;
}
void pop()
{
    if( (top) == -1)
    printf("stack underflow\n");
    else {
        printf("element popped is\n");
        printf("%d\n",s[top--]);
    }
}

void palin()
{
    int i;       //flag is not needed in this code 
    display();
    for(int i=0;i<=(top/2);i++)
        if(s[i]!=s[top-i])
        {
            printf("\nIt is not a palindrome\n");
            return;
        }
    printf("\nIt is a palindrome\n");
}
