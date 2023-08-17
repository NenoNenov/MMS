#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ITEMS_COUNT 10


typedef struct BankAccount {
    unsigned short number;
    char owner[101];
    double balance;
    char currency[5];
    struct BankAccount* next;
} BankAccount;


void generateRandomString(char* str, int minLength, int maxLength) {
    int length = rand() % (maxLength - minLength + 1) + minLength;
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            str[i] = rand() % 26 + 'A'; 
        } else {
            str[i] = rand() % 26 + 'a'; 
        }
    }
    str[length] = '\0';
}

BankAccount* createRandomBankAccount() {
    BankAccount* account = (BankAccount*)malloc(sizeof(BankAccount));
    account->number = rand() % (1 << 16); 
    generateRandomString(account->owner, 2, 5 * 20);
    account->balance = (double)rand() / RAND_MAX * 100000.0;
    
    char currencies[][4] = {"USD", "EUR", "BGN"};
    strcpy(account->currency, currencies[rand() % 3]);
    
    account->next = NULL;
    return account;
}

double totalBalance(BankAccount* head)
{
    double total = 0.0;
    while (head!=NULL)
    {
        total+=head->balance;
        head=head->next;
    }
    return total;
}

BankAccount* maxBalance(BankAccount* head) {
    BankAccount* maxAccount = NULL;
    double maxBalance = -1.0;
    while (head != NULL) {
        if (head->balance > maxBalance) {
            maxBalance = head->balance;
            maxAccount = head;
        }
        head = head->next;
    }
    return maxAccount;
}

void freeBankAccounts(BankAccount* head)
{
    while (head!=NULL)
    {
        BankAccount*temp =head;
        head=head->next;
        free(temp);
    }
    
}

int main()
{

    srand(time(NULL));
    
    BankAccount* head = NULL;
    for (int i = 0; i < ITEMS_COUNT; i++) {
        BankAccount* newAccount = createRandomBankAccount();
        newAccount->next = head;
        head = newAccount;
    }


    BankAccount* current = head;
    while (current != NULL) {
        printf("Number: %u\n", current->number);
        printf("Owner: %s\n", current->owner);
        printf("Balance: %.2f %s\n", current->balance, current->currency);
        printf("\n");
        current = current->next;
    }
    
    double total= totalBalance(head);
    if(total>=0)
    {
        printf("Total balance of all accounts: %.2f BGN\n", total);
    } else {
        printf("Failed to calculate total balance.\n");
    }
    

 
    BankAccount* max = maxBalance(head);
    if (max != NULL) {
        printf("Account with the highest balance:\n");
        printf("Number: %u\n", max->number);
        printf("Owner: %s\n", max->owner);
        printf("Balance: %.2f %s\n", max->balance, max->currency);
    } else {
        printf("No account with the highest balance found.\n");
    }
    
   
    freeBankAccounts(head);
    
    return 0;
}