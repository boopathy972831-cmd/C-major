#include "header.h"

void update_book()
{
    int id;

    BOOK *temp=head;

    printf("Enter Book ID to Update: ");
    scanf("%d",&id);

    while(temp)
    {
        if(temp->book_id==id)
        {
            printf("Enter New Title: ");
            scanf(" %[^\n]",temp->title);

            printf("Enter New Author: ");
            scanf(" %[^\n]",temp->author);

            printf("Enter New Quantity: ");
            scanf("%d",&temp->quantity);

            printf("Book Updated Successfully\n");

            return;
        }

        temp=temp->next;
    }

    printf("Book Not Found\n");
}
