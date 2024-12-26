#include <stdio.h>
//#include <stdlib.h>
#include <math.h>    // for pow()
#include <ctype.h>    // for isdigit() function

char postfix[10],symb;  //postfix is a string of symbols
int op1,op2,res;
int stack[30],i=0,top=-1;

int push(int item)
{
    stack[++top]=item;      //top is incremented and then it is passed 
}
int pop()
{
    return stack[top--];    //top is decremented and then it is passed
}
void main()
{
    printf("Enter postfix expression:\n");
    scanf("%s",postfix);
    for(i=0;postfix[i]!='\0';i++)  
    {
        symb=postfix[i];
        if(isdigit(symb))  //if the symb is an operand
        {
            push(symb-'0');    // subtraction occurs using ASCII values as symb is a char 
        }
        else               //if it is an operator
        {
            op1=pop();    //operands are poped 
            op2=pop();
            switch(symb)
            {
                case '+':res=op2+op1; break;
                case '-':res=op2-op1; break;
                case '*':res=op2*op1; break;
                case '/':res=op2/op1; break;
                case '^':res=(int)pow(op2,op1); break;    //pow() returns double so it is type casted into integer 
                default:printf("Invalid operator\n");
            }
            push(res);
        }
    }
    res=pop();      //final answer is poped 
    printf("Result is %d\n",res);
}
