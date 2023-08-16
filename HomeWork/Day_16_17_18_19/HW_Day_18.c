#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 7
#define INITIAL_BALANCE 1000
#define DEPOSIT_AMOUNT 200
#define WITHDRAW_AMOUNT 150

typedef struct {
    int balance;
    pthread_mutex_t lock;
} BankAccount;

void* deposit(void* arg) {
    BankAccount* account = (BankAccount*) arg;
    pthread_mutex_lock(&account->lock);
    account->balance += DEPOSIT_AMOUNT;
    pthread_mutex_unlock(&account->lock);
    return NULL;
}

void* withdraw(void* arg) {
    BankAccount* account = (BankAccount*) arg;
    pthread_mutex_lock(&account->lock);
    account->balance -= WITHDRAW_AMOUNT;
    pthread_mutex_unlock(&account->lock);
    return NULL;
}

int main() {
    BankAccount account;
    account.balance = INITIAL_BALANCE;
    pthread_mutex_init(&account.lock, NULL);

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, deposit, &account);
        } else {
            pthread_create(&threads[i], NULL, withdraw, &account);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final balance: %d\n", account.balance);

    pthread_mutex_destroy(&account.lock);

    return 0;
}
