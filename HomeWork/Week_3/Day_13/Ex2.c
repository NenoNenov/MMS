#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 10
#define MAX_TITLE_LENGTH 20
#define MAX_AUTHOR_LENGTH 20

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    float price;
    struct Book* next;
};

void generateRandomData(struct Book* book) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int titleLength = rand() % (MAX_TITLE_LENGTH - 10) + 10;
    int authorLength = rand() % (MAX_AUTHOR_LENGTH - 10) + 10;

    for (int i = 0; i < titleLength; i++) {
        book->title[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    book->title[titleLength] = '\0';

    for (int i = 0; i < authorLength; i++) {
        book->author[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    book->author[authorLength] = '\0';

    book->pages = rand() % 1996 + 5; 
    book->price = (float)(rand() % 100000) / 100.0; 
}

void insertSorted(struct Book** head, struct Book* newBook) {
    struct Book* current;
    if (*head == NULL || strcmp((*head)->title, newBook->title) > 0) {
        newBook->next = *head;
        *head = newBook;
    } else {
        current = *head;
        while (current->next != NULL && strcmp(current->next->title, newBook->title) <= 0) {
            current = current->next;
        }
        newBook->next = current->next;
        current->next = newBook;
    }
}

void printBooks(struct Book* head) {
    struct Book* current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Author: %s\n", current->author);
        printf("Pages: %d\n", current->pages);
        printf("Price: %.2f\n", current->price);
        printf("\n");
        current = current->next;
    }
}

void freeBooks(struct Book* head) {
    struct Book* current = head;
    while (current != NULL) {
        struct Book* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    srand(time(NULL));
    
    struct Book* head = NULL;
    
    for (int i = 0; i < COUNT; i++) {
        struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
        generateRandomData(newBook);
        insertSorted(&head, newBook);
    }
    
    printBooks(head);
    freeBooks(head);
    
    return 0;
}
