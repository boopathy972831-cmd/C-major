#include "header.h"

void issued_books()
{
    ISSUE *temp=ihead;

    if(ihead==NULL)
    {
        printf("No Issued Books\n");
        return;
    }

    printf("\n====================================================\n");

    printf("IID\tBID\tUID\tUSER\tISSUE\tDUE\tRETURN\n");

    printf("====================================================\n");

    while(temp)
    {
        printf("%d\t%d\t%d\t%s\t%s\t%s\t%s\n",
        temp->issue_id,
        temp->book_id,
        temp->user_id,
        temp->user_name,
        temp->issue_date,
        temp->due_date,
        temp->return_date);

        temp=temp->next;
    }
}
