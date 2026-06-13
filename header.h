#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book
{
    int book_id;

    char title[50];
    char author[50];

    int quantity;

    struct book *next;

}BOOK;

typedef struct issue
{
    int issue_id;

    int book_id;

    int user_id;

    char user_name[50];

    char issue_date[30];

    char due_date[30];
    
    char return_date[30];

    struct issue *next;

}ISSUE;

extern ISSUE *ihead;

extern BOOK *head;

/* Functions */

void add_book();
void show_books();

void save_books();
void read_books();

void search_book();
void update_book();
void remove_book();

void issue_book();
void return_book();

void issued_books();

void issue_book();
void return_book();
void issued_books();

void save_issue();
void read_issue();

#endif
