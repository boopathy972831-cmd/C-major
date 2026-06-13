#include "header.h"

void show_books()
{
    BOOK *temp = head;

    if(head == NULL)
    {
        printf("No Books Available\n");
        return;
    }

    printf("\n--------------------------------------------\n");

    printf("ID\tTITLE\t\tAUTHOR\t\tQTY\n");

    printf("--------------------------------------------\n");

    while(temp)
    {
        printf("%d\t%s\t\t%s\t\t%d\n",
        temp->book_id,
        temp->title,
        temp->author,
        temp->quantity);

        temp = temp->next;
    }
}
