#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int printf_time(const char *format, ...) {
    // Извличане на текущото време
    time_t rawtime;
    struct tm *timeinfo;
    char time_str[20];  // Низ за съхранение на форматираното време
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Форматиране на текущото време
    strftime(time_str, sizeof(time_str), "[%d.%m.%Y - %H:%M:%S]", timeinfo);

    // Извикване на printf със времето и подадените аргументи
    va_list args;
    va_start(args, format);
    printf("%s ", time_str);
    int result = vprintf(format, args);
    va_end(args);

    return result;
}

int main() {
    printf_time("%d %d\n", 10, 20);
    return 0;
}
