#include "header.h"
#include<time.h>

void return_book()
{
    int issueid;

    ISSUE *temp=ihead;

    printf("Enter Issue ID: ");
    scanf("%d",&issueid);

    while(temp)
    {
        if(temp->issue_id==issueid)
        {
            if(strcmp(temp->return_date,"NOT RETURNED")!=0)
            {
                printf("Already Returned\n");
                return;
            }

            time_t t=time(NULL);

            struct tm *tm=localtime(&t);

            snprintf(temp->due_date,
		sizeof(temp->due_date),
		"%02d/%02d/%04d",
		tm->tm_mday,
		tm->tm_mon + 1,
		tm->tm_year + 1900);

            BOOK *b=head;

            while(b)
            {
                if(b->book_id==temp->book_id)
                {
                    b->quantity++;
                    break;
                }

                b=b->next;
            }

            printf("Book Returned Successfully\n");

            printf("Return Date : %s\n",
            temp->return_date);

            return;
        }

        temp=temp->next;
    }

    printf("Issue Record Not Found\n");
}
