#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 10

typedef struct Book {
    char title[151];
    char author[101];
    int pages;
    double price;
} Book;

int compare_books(const void *a, const void *b) {
    const Book *book1 = (const Book *)a;
    const Book *book2 = (const Book *)b;

    int title_cmp = strcmp(book1->title, book2->title);
    if (title_cmp != 0) {
        return title_cmp;
    }

    int author_cmp = strcmp(book1->author, book2->author);
    if (author_cmp != 0) {
        return author_cmp;
    }

    if (book1->pages != book2->pages) {
        return book1->pages - book2->pages;
    }

    return (book1->price > book2->price) - (book1->price < book2->price);
}

void print_books(Book *books, int count) {
    for (int i = 0; i < count; i++) {
        printf("Title: %s\nAuthor: %s\nPages: %d\nPrice: %.2lf\n\n",
               books[i].title, books[i].author, books[i].pages, books[i].price);
    }
}

int main() {
    Book books[COUNT];

    for (int i = 0; i < COUNT; i++) {
        sprintf(books[i].title, "Title%d", i);
        sprintf(books[i].author, "Author%d", i);
        books[i].pages = rand() % 1996 + 5; 
        books[i].price = (rand() % 100000) / 100.0; 
    }

    qsort(books, COUNT, sizeof(Book), compare_books);

    printf("Sorted books by title:\n");
    print_books(books, COUNT);

    return 0;
}
