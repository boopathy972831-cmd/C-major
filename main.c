#include "header.h"

BOOK *head = NULL;
ISSUE *ihead = NULL;

int main()
{
    int op;

    read_books();

    read_issue();

    while(1)
    {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");

        printf("1. Add New Book\n");
        printf("2. Update Book Details\n");
        printf("3. Remove Book\n");
        printf("4. Search Book\n");
        printf("5. View All Books\n");
        printf("6. Issue Book\n");
        printf("7. Return Book\n");
        printf("8. List Issued Books\n");
        printf("9. Save\n");
        printf("10. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                add_book();
                break;

            case 2:
                update_book();
                break;

            case 3:
                remove_book();
                break;

            case 4:
                search_book();
                break;

            case 5:
                show_books();
                break;

            case 6:
                issue_book();
                break;

            case 7:
                return_book();
                break;

            case 8:
                issued_books();
                break;

	    case 9:

   		save_books();


    		save_issue();

		break;

	    case 10:
                exit(0);
        }
    }
}
