#include <stdio.h>
#include<stdlib.h>

#define NODE_SIZE 5

typedef struct circular
{
    int data;
    struct circular *link;
}cll;

void insert(cll **head_arg, int data);
void print(cll **head_arg);
void delete_at_last(cll **head_arg);

int main()
{
    int data, i = 0;
    cll *head = NULL;
    while(i++ < NODE_SIZE)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(&head, data);
    }
    print(&head);
    delete_at_last(&head);
    return 0;
}

void insert(cll **head_arg, int data)
{
    cll *new = (cll *)malloc(sizeof(cll));
    if(new == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        new->data = data;
        new->link = NULL;
        if(*head_arg == NULL)
        {
            *head_arg = new;
            new->link = *head_arg;
        }
        else
        {
            cll *temp = *head_arg;
            while(temp->link != *head_arg)
            {
                temp = temp->link;
            }
            temp->link = new;
            new->link = *head_arg;
        }
    }
}

void print(cll **head_arg)
{
    cll *temp;
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = *head_arg;
        do
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }while(temp != *head_arg);
        printf("\n");
    }
}

void delete_at_last(cll **head_arg)
{
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        cll *temp = *head_arg;
        cll *prev = NULL;
        while(temp->link != *head_arg)
        {
            prev = temp;
            temp = temp->link;
        }
        printf("The deleted element is %d\n", temp->data);
        free(temp);
        prev->link = *head_arg;
    }
}
