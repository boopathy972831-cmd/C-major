#include "header.h"

void save_books()
{
    FILE *fp = fopen("books.csv","w");

    if(fp == NULL)
    {
        printf("File Error\n");
        return;
    }

    BOOK *temp = head;

    fprintf(fp,"BookID,Title,Author,Quantity\n");

    while(temp)
    {
        fprintf(fp,"%d,%s,%s,%d\n",
        temp->book_id,
        temp->title,
        temp->author,
        temp->quantity);

        temp = temp->next;
    }

    fclose(fp);

    printf("Books Saved Successfully\n");
}

void read_books()
{
    FILE *fp = fopen("books.csv","r");

    if(fp == NULL)
        return;

    char line[200];

    fgets(line,sizeof(line),fp);

    while(1)
    {
        BOOK *new = malloc(sizeof(BOOK));

        if(fscanf(fp,"%d,%49[^,],%49[^,],%d\n",
        &new->book_id,
        new->title,
        new->author,
        &new->quantity) != 4)
        {
            free(new);
            break;
        }

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
    }

    fclose(fp);
}
