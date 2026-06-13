#include "header.h"

void add_book()
{
    BOOK *new = malloc(sizeof(BOOK));

    printf("Enter Book ID: ");
    scanf("%d",&new->book_id);

    printf("Enter Title: ");
    scanf(" %[^\n]",new->title);

    printf("Enter Author: ");
    scanf(" %[^\n]",new->author);

    printf("Enter Quantity: ");
    scanf("%d",&new->quantity);

    new->next = NULL;

    if(head == NULL)
    {
        head = new;
    }
    else
    {
        BOOK *temp = head;

        while(temp->next)
            temp = temp->next;

        temp->next = new;
    }

    printf("Book Added Successfully\n");
}
