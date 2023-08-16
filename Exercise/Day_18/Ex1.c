#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define INIT_BALANCE 1000

typedef struct {
    int balance; // Balance of account
    pthread_mutex_t lock; // Mutex for synchronization
} BalanceAccount;

BalanceAccount account;

void deposit(void *arg) {
    int *amount = (int *)arg;
    pthread_mutex_lock(&account.lock);
    account.balance += *amount;
    pthread_mutex_unlock(&account.lock);
}

void withdraw(void *arg) {
    int *amount = (int *)arg;
    pthread_mutex_lock(&account.lock);
    account.balance -= *amount;
    pthread_mutex_unlock(&account.lock);
}

int main(int argc, char *argv[]) {
    account.balance = INIT_BALANCE;
    pthread_mutex_init(&account.lock, NULL);

    pthread_t threads[NUM_THREADS];

    int deposit_amount = 200;
    int withdraw_amount = 100;

    for (size_t i = 0; i < NUM_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, deposit, &deposit_amount);
        } else {
            pthread_create(&threads[i], NULL, withdraw, &withdraw_amount);
        }
    }

    for (size_t i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&account.lock);

    printf("Final account balance: %d\n", account.balance);

    return 0;
}
