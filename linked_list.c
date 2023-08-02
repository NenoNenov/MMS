#include <stdio.h>
#include <stdlib.h>
typedef struct Data
{
    int val;
}Data;

typedef struct Node
{
    Data d;
    struct Node *next;

}Node;

void print_linked_list(Node *head)
{
      while (head != NULL) {
    printf("%d ", head->d.val);
    head = head->next;
    }
    /*
    printf("%d",head->val);
    printf("%d",head->next->val);
    printf("%d",head->next->next->val);
    */
    
}
void push_back(Node** head_ref, Data val) {
     Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->d = val;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void pop_back(Node **head_ref) {
    if (*head_ref == NULL) {
        return;  
    }

    if ((*head_ref)->next == NULL) {
        free(*head_ref);  
        *head_ref = NULL;
        return;
    }

    Node *prev = NULL;
    Node *current = *head_ref;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    free(current);
    prev->next = NULL;
}

void push_front(Node **head_ref, Data val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->d = val;
    new_node->next = *head_ref;

    *head_ref = new_node;
}

void pop_front(Node **head_ref) {
    if (*head_ref == NULL) {
        return;
    }

    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}
void insert_after(Node *prev_node, Data val) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->d = val;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void remove_all(Node **head_ref) {
    Node *current = *head_ref;
    Node *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head_ref = NULL; 
}
int main() {
    Node *n1 = NULL;
    Node * head=n1;

    push_back(&head,(Data){6});
    push_back(&head,(Data){8});
    push_back(&head,(Data){7});

    Node *node_to_insert_after = head; 
    insert_after(node_to_insert_after, (Data){10});
    print_linked_list(head);
    //Pop back
    pop_back(&head); 
    printf("\n");
    print_linked_list(head);

    //Push front
    push_front(&head,(Data){1});
    printf("\n");
    print_linked_list(head);
    
    //Pop front
    pop_front(&head); 
    printf("\n");
    print_linked_list(head);

    remove_all(&head); // Remove all elements
    printf("\nLinked list after removing all elements:\n");
    print_linked_list(head);
    
    printf("\n");
    
    return 0;
}