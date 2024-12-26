/*7. Develop a menu driven Program in C for the following operations on Singly Linked List 
(SLL) of Student Data with the fields: USN, Name, Programme, Sem, 
PhNo 
a. Create a SLL of N Students Data by using front insertion. 
b. Display the status of SLL and count the number of nodes in it 
c. Perform Insertion / Deletion at End of SLL 
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack) 
e. Exit */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char usn[25], name[25], branch[25];
    int sem;
    long int ph;
    struct node *link;
}NODE;

NODE *start = NULL;
int count = 0;

NODE* create()
{
    NODE *snode;
    snode = (NODE *)malloc(sizeof(NODE));
    if (snode == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter USN, Name, Branch, Sem, Phone no:\n");
    scanf("%s %s %s %d %ld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->ph);
    snode->link = NULL;
    count++;
    return snode;
}

void insertfront()
{
    NODE *temp;
    temp = create();
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->link = start;
        start = temp;
    }
}

void deletefront()
{
    if (start == NULL)
    {
        printf("Deletion not possible\n");
        return;
    }
    else if (start->link == NULL)
    {
        printf("Student with USN %s deleted\n", start->usn);
        start = NULL;
    }
    else
    {
        printf("Student with USN %s deleted\n", start->usn);
        start = start->link;
    }
    count--;
}

void insertend()
{
    NODE *temp, *cur;
    temp = create();
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        cur = start;
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = temp;
    }
}

void deleteend()
{
    NODE *cur;
    if (start == NULL)
    {
        printf("Deletion not possible\n");
        return;
    }
    else if (start->link == NULL)
    {
        printf("Student with USN %s deleted\n", start->usn);
        start = NULL;
    }
    else
    {
        cur = start;
        while (cur->link->link != NULL)
        {
            cur = cur->link;
        }
        printf("Student with USN %s deleted\n", cur->link->usn);
        cur->link = NULL;
    }
    count--;
}

void display()
{
    NODE *cur;
    if (start == NULL)
    {
        printf("Display not possible\n");
        return;
    }
    else
    {
        printf("The contents are:\n");
        cur = start;
        while (cur != NULL)
        {
            printf("USN:%s Name:%s Branch:%s Sem:%d Ph:%ld\n", cur->usn, cur->name, cur->branch, cur->sem, cur->ph);
            cur = cur->link;
        }
    }
    printf("The total nodes are: %d\n", count);
}

void stackdemo()
{
    int ch;
    while (1)
    {
        printf("*****Stack Demo******");
        printf("1.Push 2.Pop 3.Display 4.Return\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: insertfront(); break;
            case 2: deletefront(); break;
            case 3: display(); break;
            case 4: return;
            default: printf("Enter a valid choice\n"); break;
        }
    }
}

void main()
{
    int ch;
    while (1)
    {
        printf("1.Insert data to SLL for n students\n");
        printf("2.Insert end\n");
        printf("3.Delete end\n");
        printf("4.Stack demonstration using SLL\n");
        printf("5.Display status of SLL\n");
        printf("6.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter the value of N: ");
                int n;
                scanf("%d", &n);
                for (int i = 0; i < n; i++)
                {
                    insertfront();
                }
                break;
            case 2: insertend(); break;
            case 3: deleteend(); break;
            case 4: stackdemo(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Enter a valid choice\n");
        }
    }
}
