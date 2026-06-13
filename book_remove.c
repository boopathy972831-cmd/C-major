#include "header.h"

void remove_book()
{
    int id;

    printf("Enter Book ID to Remove: ");
    scanf("%d",&id);

    BOOK *temp=head,*prev=NULL;

    while(temp)
    {
        if(temp->book_id==id)
        {
            if(temp==head)
                head=temp->next;

            else
                prev->next=temp->next;

            free(temp);

            printf("Book Removed Successfully\n");

            return;
        }

        prev=temp;
        temp=temp->next;
    }

    printf("Book Not Found\n");
}
