#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createCyclicLinkedList(int N, int numbers[]) {
    if (N <= 0) {
        return NULL;
    }

    struct Node *first = NULL;
    struct Node *last = NULL;

    for (int i = 0; i < N; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            return NULL;
        }

        newNode->data = numbers[i];
        newNode->next = NULL;

        if (first == NULL) {
            first = newNode;
            last = newNode;
            last->next = first;  
        } else {
            last->next = newNode;
            last = newNode;
            last->next = first;  
        }
    }

    return first;
}

void print(struct Node *cll) {
    if (cll == NULL) {
        return;
    }

    struct Node *current = cll;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != cll);

    printf("\n");
}

struct Node *insertAfter(struct Node *cll, int skipCount, int newElem) {
    if (cll == NULL || skipCount < 0) {
        return NULL;
    }

    struct Node *current = cll;

    for (int i = 0; i < skipCount; i++) {
        current = current->next;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = newElem;
    newNode->next = current->next;
    current->next = newNode;

    return newNode;
}

int main() {
    int N;
    scanf("%d", &N);

    int numbers[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    struct Node *cyclicList = createCyclicLinkedList(N, numbers);
    if (cyclicList == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    print(cyclicList);

    int skipCount, newElem;
    scanf("%d %d", &skipCount, &newElem);

    struct Node *newNode = insertAfter(cyclicList, skipCount, newElem);
    if (newNode == NULL) {
        printf("Insertion error\n");
        return 1;
    }

    print(cyclicList);

    struct Node *current = cyclicList;
    struct Node *nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != cyclicList);

    return 0;
}
