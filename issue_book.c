#include "header.h"
#include <time.h>

void issue_book()
{
    int id;

    BOOK *temp = head;

    printf("Enter Book ID: ");
    scanf("%d",&id);

    while(temp)
    {
        if(temp->book_id == id)
        {
            if(temp->quantity <= 0)
            {
                printf("Book Not Available\n");
                return;
            }

            ISSUE *new = malloc(sizeof(ISSUE));

            printf("Enter Issue ID: ");
            scanf("%d",&new->issue_id);

            new->book_id = id;

            printf("Enter User ID: ");
            scanf("%d",&new->user_id);

            printf("Enter User Name: ");
            scanf(" %[^\n]",new->user_name);

            time_t t = time(NULL);

            struct tm *tm = localtime(&t);

            /* Issue Date */

            snprintf(new->issue_date,
            sizeof(new->issue_date),
            "%02d/%02d/%04d",
            tm->tm_mday,
            tm->tm_mon + 1,
            tm->tm_year + 1900);

            /* Due Date = 7 days later */

            t = t + (7 * 24 * 60 * 60);

            tm = localtime(&t);

            snprintf(new->due_date,
            sizeof(new->due_date),
            "%02d/%02d/%04d",
            tm->tm_mday,
            tm->tm_mon + 1,
            tm->tm_year + 1900);

            strcpy(new->return_date,"NOT RETURNED");

            new->next = NULL;

            if(ihead == NULL)
            {
                ihead = new;
            }
            else
            {
                ISSUE *t1 = ihead;

                while(t1->next)
                    t1 = t1->next;

                t1->next = new;
            }

            temp->quantity--;

            printf("Book Issued Successfully\n");

            printf("Issue Date : %s\n",new->issue_date);

            printf("Due Date : %s\n",new->due_date);

            return;
        }

        temp = temp->next;
    }

    printf("Book Not Found\n");
}



void save_issue()
{
    FILE *fp = fopen("issue.csv","w");

    if(fp == NULL)
        return;

    ISSUE *temp = ihead;

    fprintf(fp,
    "IssueID,BookID,UserID,UserName,IssueDate,DueDate,ReturnDate\n");

    while(temp)
    {
        fprintf(fp,"%d,%d,%d,%s,%s,%s,%s\n",
        temp->issue_id,
        temp->book_id,
        temp->user_id,
        temp->user_name,
        temp->issue_date,
        temp->due_date,
        temp->return_date);

        temp = temp->next;
    }

    fclose(fp);
}



void read_issue()
{
    FILE *fp = fopen("issue.csv","r");

    if(fp == NULL)
        return;

    char line[300];

    fgets(line,sizeof(line),fp);

    while(1)
    {
        ISSUE *new = malloc(sizeof(ISSUE));

        if(fscanf(fp,
        "%d,%d,%d,%49[^,],%29[^,],%29[^,],%29[^\n]\n",
        &new->issue_id,
        &new->book_id,
        &new->user_id,
        new->user_name,
        new->issue_date,
        new->due_date,
        new->return_date) != 7)
        {
            free(new);
            break;
        }

        new->next = NULL;

        if(ihead == NULL)
        {
            ihead = new;
        }
        else
        {
            ISSUE *t1 = ihead;

            while(t1->next)
                t1 = t1->next;

            t1->next = new;
        }
    }

    fclose(fp);
}
