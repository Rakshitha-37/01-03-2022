#include <stdio.h>
#include<stdlib.h>

#define NODE_SIZE 5

typedef struct node
{
    int data;
    struct node *link;
}sll;

sll *head = NULL;

void insert(int data);
void print();
int search(int element);
void sort();

int main()
{
    int data, i = 0;
    while(i++ < NODE_SIZE)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(data);
    }
    printf("Before swapping: ");
    print();
    sort();
    printf("After swapping: ");
    print();
    
    return 0;
}

void insert(int data)
{
    sll *new = (sll *)malloc(sizeof(sll));
    if(new == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        new->data = data;
        new->link = NULL;
        if(head == NULL)
        {
            head = new;
        }
        else
        {
            sll *temp = head;
            while(temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = new;
        }
    }
}

void print()
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void sort()
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        int temporary;
        sll *temp = head;
        sll *temp1;
        while(temp != NULL)
        {
            temp1 = temp->link;
            while(temp1 != NULL)
            {
                if(temp->data > temp1->data)
                {
                    temporary = temp->data;
                    temp->data = temp1->data;
                    temp1->data = temporary;
                }
                temp1 = temp1->link;
            }
            temp = temp->link;
        }
    }
}
