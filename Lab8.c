/*8. Develop a menu driven Program in C for the following operations on Doubly Linked List 
(DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, 
Sal, PhNo 
a. Create a DLL of N Employees Data by using end insertion. 
b. Display the status of DLL and count the number of nodes in it 
c. Perform Insertion and Deletion at End of DLL 
d. Perform Insertion and Deletion at Front of DLL 
e. Demonstrate how this DLL can be used as Double Ended Queue. 
f. Exit */
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char ssn[25],name[25],dept[25],desg[25];
    int sal;
    long int phno;
    struct node *llink;
    struct node *rlink;
}NODE;

NODE *start;
int count=0;
NODE* create()
{
    NODE *enode;
    enode=(NODE *)malloc(sizeof(NODE));
    if(enode==NULL)
    {
        printf("Memory is not allocated\n");
        exit(0);
    }
    printf("Enter ssn,name,dept,desg,sal,phno\n");
    scanf("%s %s %s %s %d %ld",enode->ssn,enode->name,enode->dept,enode->desg,&enode->sal,&enode->phno);
    enode->llink=NULL;
    enode->rlink=NULL;
    count++;
    return enode;
}
void insertfront()
{
    NODE *temp;
    temp=create();
    if(start==NULL)
      start=temp;
    else
    {
        temp->rlink=start;
        start->llink=temp;
        start=temp;
    }
}

void insertend()
{
    NODE *temp,*cur;
    temp=create();
    if(start==NULL)
       start=temp;
    else if(start->rlink==NULL){
       start->rlink=temp;
       temp->llink=start;
    }
    else
    {
        cur=start;
        while(cur->rlink!=NULL)
          cur=cur->rlink;
        cur->rlink=temp;
        temp->llink=cur;
    }
}

void deletefront()
{
    if(start==NULL)
    {
        printf("Deletion not possible\n");
        return;
    }
    else if(start->rlink==NULL)
    {
        printf("Employee data with ssn %s deleted\n",start->ssn);
        start=NULL;
    }
    else
    {
        printf("Employee data with ssn %s deleted\n",start->ssn);
        start=start->rlink;
        start->llink=NULL;
    }
    count--;
}

void deleteend()
{
    NODE *cur;
    if(start==NULL)
    {
      printf("Deletion not possible\n");
    }
    else if(start->rlink==NULL)
    {
        printf("Employee data with ssn %s deleted\n",start->ssn);
        start=NULL;
        count--;
    }
     else
    {
        cur=start;
        while(cur->rlink->rlink!=NULL)
          cur=cur->rlink;
        printf("Employee data with ssn %s deleted\n",cur->rlink->ssn);
        cur->rlink=NULL;
        count--;
    }
}

void display()
{
    NODE *cur;
    if(start==NULL){
      printf("Display not possible\n");
      return;   //It was commented 
    }
    else
    {
        cur=start;
        while(cur!=NULL)
        {
            printf("SSN:%s Name:%s Dept:%s Desg:%s Sal:%d Ph no:%ld\n",cur->ssn,cur->name,cur->dept,cur->desg,cur->sal,cur->phno);
            cur=cur->rlink;
        }
    }
    printf("Tne total employees are:%d",count);
}

void dequeuedemo()
{
    int ch;
    while(1)
    {
        printf("*****Dequeue demo*****\n");
        printf("1.Insertfront 2.Deletefront 3.Insertrear 4.Deleterear 5.Display 6.return\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertfront(); break;
            case 2:deletefront(); break;
            case 3:insertend(); break;
            case 4:deleteend(); break;
            case 5:display(); break;
            case 6:return;
            default:printf("Invalid choice\n");
        }
    }
}

void main()
{
    int i,n,ch;
    while(1)
    {
        printf("******DLL demo******\n");
        printf("1.Create DLL for n employee\n");
        printf("2.Display DLL status\n");
        printf("3.Insert front\n");
        printf("4.Delete front\n");
        printf("5.Insert end\n");
        printf("6.Delete end\n");
        printf("7.Demo of Dequeue\n");
        printf("8.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   printf("Enter value of n:\n");
                   scanf("%d",&n);
                   for(i=1;i<=n;i++)
                     insertend();
                   break;
            case 2:display(); break;
            case 3:insertfront(); break;
            case 4:deletefront(); break;
            case 5:insertend(); break;
            case 6:deleteend(); break;
            case 7:dequeuedemo(); break;
            case 8:exit(0);
            default:printf("Enter valid input\n");
        }
    }
}
