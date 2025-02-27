/*
 Ya program madhe DeleteFirst function madhe temporary pointer use kela 
 ahe.            i.e PNODE temp = NULL; 
 Next program325 madhe temporary pointer na use karta DeleteFirst Function 
 lihla ahe.

*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }

}

void InsertLast(PPNODE head , int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
        
    }

}

void InsertAtPos(PPNODE head , int no , int ipos)
{

}

void Display(PNODE head)
{
    printf("Elements of the LinkedList are : \n");

    printf("NULL  <=>");

    while(head != NULL)
    {
        printf("| %d | <=>",head->data);
        head = head->next;
    }
    printf("NULL \n");

}

int Count(PNODE head)
{
    int iCount = 0;

    while(head != NULL)
    {
        iCount++;
        head = head->next;
    }
    return iCount;

}

void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)           //  Case 1
    {
        return;
    }

    else if ((*head) -> next == NULL)    // Case 2
    {
        free(*head);
        *head = NULL;
    }

    else                             // Case 3
    {
        temp = *head;

        *head = (*head)->next;
        free(temp);
        (*head)->prev = NULL;    //$
        
    }
}

void DeleteLast(PPNODE head)
{
    if(*head == NULL)           //  Case 1
    {
        return;
    }

    else if ((*head) -> next == NULL)    // Case 2
    {
        free(*head);
        *head = NULL;
    }
    
    else                             // Case 3
    {

    }

}

void DeleteAtPos(PPNODE head , int ipos)
{

}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first , 51);
    InsertFirst(&first , 21);
    InsertFirst(&first , 11);

    InsertLast(&first , 101);
    InsertLast(&first , 111);
    InsertLast(&first , 121);

    Display(first);
    iRet = Count(first);
    printf("Number of elements are : %d\n",iRet);

    DeleteFirst(&first);

    Display(first);
    iRet = Count(first);
    printf("Number of elements are : %d\n",iRet);

    return 0;
}