#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONS 100
#define ID_LEN 10

struct Person {
    char name[100];
    char id[ID_LEN];
    unsigned short birthYear;
    unsigned char birthMonth;
    unsigned char birthDay;
    char gender;
};

struct PersonArray {
    struct Person* persons;
    size_t size;
    size_t capacity;
};

struct PersonArray* initArray(size_t capacity) {
    struct PersonArray* arr = (struct PersonArray*)malloc(sizeof(struct PersonArray));
    arr->persons = (struct Person*)malloc(sizeof(struct Person) * capacity);
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

int addPerson(struct PersonArray* arr, char *name, unsigned short birthYear, unsigned char birthMonth, unsigned char birthDay, char gender) {
    if (arr->size >= arr->capacity) {
        return -1; 
    }

    if (strlen(name) >= sizeof(arr->persons[arr->size].name)) {
        return -1;
    }

    if (strlen(arr->persons[arr->size].id) >= ID_LEN) {
        return -1; 
    }

  
    strcpy(arr->persons[arr->size].name, name);
    snprintf(arr->persons[arr->size].id, ID_LEN, "%d", arr->size);
    arr->persons[arr->size].birthYear = birthYear;
    arr->persons[arr->size].birthMonth = birthMonth;
    arr->persons[arr->size].birthDay = birthDay;
    arr->persons[arr->size].gender = gender;

    arr->size++;
    return 0;
}

int removePerson(struct PersonArray* arr, char *id) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->persons[i].id, id) == 0) {
            
            arr->persons[i] = arr->persons[arr->size - 1];
            arr->size--;
            return 0;
        }
    }
    return -1; 
}

void readPerson(struct PersonArray* arr) {
    char name[100];
    unsigned short birthYear;
    unsigned char birthMonth, birthDay;
    char gender;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter birth year: ");
    scanf("%hu", &birthYear);

    printf("Enter birth month: ");
    scanf("%hhu", &birthMonth);

    printf("Enter birth day: ");
    scanf("%hhu", &birthDay);

    printf("Enter gender (M/F): ");
    scanf(" %c", &gender);

    addPerson(arr, name, birthYear, birthMonth, birthDay, gender);
}

int printPerson(struct PersonArray* arr, char *id) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->persons[i].id, id) == 0) {
            printf("Name: %s\n", arr->persons[i].name);
            printf("ID: %s\n", arr->persons[i].id);
            printf("Birth Year: %hu\n", arr->persons[i].birthYear);
            printf("Birth Month: %hhu\n", arr->persons[i].birthMonth);
            printf("Birth Day: %hhu\n", arr->persons[i].birthDay);
            printf("Gender: %c\n", arr->persons[i].gender);
            return 0;
        }
    }
    return -1; 
}


int main() {
    struct PersonArray* persons = initArray(MAX_PERSONS);

    addPerson(persons, "John", 1990, 7, 15, 'M');
    addPerson(persons, "Jane", 1985, 3, 25, 'F');
    addPerson(persons, "Michael", 2000, 9, 5, 'M');

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Person\n");
        printf("2. Remove Person\n");
        printf("3. Print Person\n");
        printf("4. Print All Persons\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readPerson(persons);
                break;
            case 2: {
                char idToRemove[ID_LEN];
                printf("Enter the ID of the person you want to remove: ");
                scanf("%s", idToRemove);
                if (removePerson(persons, idToRemove) == 0) {
                    printf("Person with ID %s removed successfully.\n", idToRemove);
                } else {
                    printf("Person with ID %s not found.\n", idToRemove);
                }
                break;
            }
            case 3: {
                char searchId[ID_LEN];
                printf("Enter an ID to search for: ");
                scanf("%s", searchId);
                if (printPerson(persons, searchId) == -1) {
                    printf("Person with ID %s not found.\n", searchId);
                }
                break;
            }
            case 4:
                printf("\nAll persons:\n");
                for (size_t i = 0; i < persons->size; i++) {
                    printf("ID: %s, Name: %s\n", persons->persons[i].id, persons->persons[i].name);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);

   
    free(persons->persons);
    free(persons);

    return 0;
}
