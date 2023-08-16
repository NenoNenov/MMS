#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint32_t year;   // Максимална стойност: 2^32 - 1 (достатъчно за години до 2106)
    uint32_t month;  // Максимална стойност: 2^32 - 1 (достатъчно за месеци до 12)
    uint32_t day;    // Максимална стойност: 2^32 - 1 (достатъчно за дни до 31)
    uint32_t hour;   // Максимална стойност: 2^32 - 1 (достатъчно за часове до 23)
    uint32_t minute; // Максимална стойност: 2^32 - 1 (достатъчно за минути до 59)
    uint32_t second; // Максимална стойност: 2^32 - 1 (достатъчно за секунди до 59)
} MyTime;

int isLeapYear(MyTime t) {
    int year = t.year + 1970;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int totalDaysInYear(MyTime t) {
    return isLeapYear(t) ? 366 : 365;
}

void printMonth(MyTime t) {
    const char* months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("%s\n", months[t.month - 1]);
}

int secondsPassed(MyTime t) {
    int year = t.year + 1970;
    uint64_t days = 0;

    for (int i = 1970; i < year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            days += 366;
        } else {
            days += 365;
        }
    }

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(t)) {
        monthDays[1] = 29;
    }

    for (int i = 0; i < t.month - 1; i++) {
        days += monthDays[i];
    }

    days += t.day - 1;

    uint64_t seconds = days * 24 * 60 * 60 + t.hour * 60 * 60 + t.minute * 60 + t.second;

    return (int)seconds; // Преобразуваме обратно към int за връщане от функцията
}

int main() {
    MyTime t1 = {1970, 1, 1, 0, 0, 0};
    MyTime t2 = {2001, 1, 1, 0, 0, 0};

    printf("Size of MyTime struct: %zu bytes\n", sizeof(MyTime));
    printf("Total seconds passed between 1st January 1970 and 1st January 2001: %d\n", secondsPassed(t2) - secondsPassed(t1));
    printf("Size of MyTime struct: %zu bytes\n", sizeof(MyTime));
    
    printf("Is leap year? %d\n", isLeapYear(t2));
    printf("Total days in the year: %d\n", totalDaysInYear(t2));
    printf("Month: ");
    printMonth(t2);
    return 0;
}
