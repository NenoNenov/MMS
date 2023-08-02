#include <stdio.h>

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



int main() {
    Node n1, n2, n3;
    n1.d.val = 13;
    n1.next = &n2;

    n2.d.val = 15;
    n2.next = &n3;
    n3.d.val = 20;
    n3.next = NULL;

    print_linked_list(&n1);

    push_back(&(n2.next), (Data){25}); // Добавяне на нов елемент
    printf("\n");
    print_linked_list(&n1);

    return 0;
}