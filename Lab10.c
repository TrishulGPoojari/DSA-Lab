/*10. Develop a menu driven Program in C for the following operations on Binary Search Tree 
(BST) of Integers . 
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2 
b. Traverse the BST in Inorder, Preorder and Post Order 
c. Search the BST for a given element (KEY) and report the appropriate message 
d. Exit 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST *lchild;
    struct BST *rchild;
}NODE;

NODE* create() 
{
    NODE *temp;
    temp = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the value: ");
    scanf("%d", &temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;                      //here the link is referred to as a child 
    return temp;
}

void insert(NODE *root, NODE *newnode) {
    if (newnode->data < root->data)         //if the number is less, move it to the left side 
    {
        if (root->lchild == NULL)
            root->lchild = newnode;
        else
            insert(root->lchild, newnode);      //if the left node is not empty 
    } 
    else if (newnode->data > root->data)        //if the number is greater move it to the right side 
    {
        if (root->rchild == NULL)
            root->rchild = newnode;
        else
            insert(root->rchild, newnode);
    }
}

void inorder(NODE *root)
{
    if (root != NULL)                       //To traverse to all the nodes, it works well recurrsion logic 
    {                                       //If the node is empty it will return to the function call
        inorder(root->lchild);              //if here acts a loop due to recursive function call
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void preorder(NODE *root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE *root) 
{
    if (root != NULL) 
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

void search(NODE *root)
{
    int key;
    NODE *cur;                  //A pointer to traverse the tree is used 
    if (root == NULL)           
    {
        printf("\nBST is empty.");
        return;
    }
    printf("\nEnter element to be searched: ");
    scanf("%d", &key);
    cur = root;
    while (cur != NULL) 
    {
        if (cur->data == key) 
        {
            printf("\nKey element %d is present in BST.", key);
            return;
        }
        if (key < cur->data)
            cur = cur->lchild;
        else
            cur = cur->rchild;
    }
    printf("\nKey element %d is not found in the BST.", key);
}
// The case where Root is empty is handled in the main function itself
void main() {
    int ch, n, i;
    NODE *root = NULL, *newnode;

    while (1) {
        printf("\n-------BST MENU-------");
        printf("\n1. Create a BST");
        printf("\n2. Search");
        printf("\n3. BST Traversals");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            for (i = 1; i <= n; i++) 
            {
                newnode = create();
                if (root == NULL)
                    root = newnode;
                else
                    insert(root, newnode);
            }
            break;

        case 2:
            search(root);
            break;

        case 3:
            if (root == NULL)
                printf("\nTree is not created.");
            else {
                printf("\nThe Preorder display: ");
                preorder(root);
                printf("\nThe Inorder display: ");
                inorder(root);
                printf("\nThe Postorder display: ");
                postorder(root);
            }
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }
}
