#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));    // Allocate the memory

    newn->data = no;                       // Initialise the members
    newn->next = NULL;

    if(*head == NULL)    // Case 1 (LinkedList is empty)
    {
       *head = newn;
    }
    else                // Case 2 (LinkedList contains atleast 1 node)
    {
        newn->next = *head;
        *head = newn;

    }
   
}

int main()
{
    PNODE first = NULL;

    InsertFirst(&first , 51);
    InsertFirst(&first , 21);
    InsertFirst(&first , 11);

    return 0;
}