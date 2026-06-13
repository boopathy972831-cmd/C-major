#include "header.h"

void search_book()
{
    int ch,id,found=0;
    char name[50],author[50];

    BOOK *temp=head;

    printf("\n1. Search By ID\n");
    printf("2. Search By Title\n");
    printf("3. Search By Author\n");

    printf("Enter Choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:

            printf("Enter Book ID: ");
            scanf("%d",&id);

            while(temp)
            {
                if(temp->book_id==id)
                {
                    printf("\n%d\t%s\t%s\t%d\n",
                    temp->book_id,
                    temp->title,
                    temp->author,
                    temp->quantity);

                    found=1;
                }

                temp=temp->next;
            }

            break;

        case 2:

            printf("Enter Title: ");
            scanf(" %[^\n]",name);

            while(temp)
            {
                if(strcmp(temp->title,name)==0)
                {
                    printf("\n%d\t%s\t%s\t%d\n",
                    temp->book_id,
                    temp->title,
                    temp->author,
                    temp->quantity);

                    found=1;
                }

                temp=temp->next;
            }

            break;

        case 3:

            printf("Enter Author: ");
            scanf(" %[^\n]",author);

            while(temp)
            {
                if(strcmp(temp->author,author)==0)
                {
                    printf("\n%d\t%s\t%s\t%d\n",
                    temp->book_id,
                    temp->title,
                    temp->author,
                    temp->quantity);

                    found=1;
                }

                temp=temp->next;
            }

            break;
    }

    if(found==0)
        printf("Book Not Found\n");
}
