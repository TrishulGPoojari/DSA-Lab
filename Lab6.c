//Implimentation of circular queue using arrays
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

char queue[MAX],front=-1,rear=-1; // making it global variable so that it can be accessed easily 

void enqueue()
{
    if(front==((rear+1)%MAX))
        printf("Queue overflow\n");
    else
    {
            if(front==-1)
                front++;
            rear=rear=(rear+1)%5;
            printf("Enter the character to be inserted:\n");
            scanf("%c",&queue[rear]);
            getchar();
    }
}
char dequeue(){
    if(rear==-1 && front==-1)
    {
        printf("queue UNDERFLOW");
    }
    else
    {
        printf("Element deleted is %c",queue[front]);
        if(front==rear)
            front=rear=-1;
        else
            front=(front+1)%MAX;
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("Display not possible");
    }
    else{
        int i;
        printf("\nQueue elements are: ");
        for(i=front;i!=rear;i=(i+1)%MAX)
        {
            printf("%c ",queue[i]);
        }
        printf("%c ",queue[i]);   //the last element is printed here
        printf("\n Front is at %d\nRear is at %d\n",front,rear);
        }
}

int main()
{
    int ch,n;
    printf("******Circular Queue Operations******");
    while(1)
    {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        printf("Enter the choice:\n");
        scanf("%d",&ch);
        getchar();   //to remove the newline character from the input buffer
        switch(ch)
        {
            case 1:
                printf("Enter the number of character:\n");
                scanf("%d",&n);
                getchar();  //if the problem is with display try using getchar() after scanf in any code 
                for(int i=0;i<n;i++)
                    enqueue(); 
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4:exit(0);
            default:printf("Enter a valid input\n"); break;
        }
    }
}
