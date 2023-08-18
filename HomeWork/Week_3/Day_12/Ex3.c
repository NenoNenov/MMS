#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int printed_chars = 0;

    while (*fmt != '\0') {
        if (*fmt == '%') {
            fmt++;  // Прескачаме '%' символа
            char specifier = *fmt;

            if (specifier == 'd') {
                int value = va_arg(args, int);
                printed_chars += printf("%d", value);
            } else if (specifier == 'f') {
                double value = va_arg(args, double);
                printed_chars += printf("%f", value);
            } else if (specifier == 'c') {
                int value = va_arg(args, int);  // 'char' се предава като 'int'
                printed_chars += putchar(value);
            }
        } else {
            putchar(*fmt);
            printed_chars++;
        }

        fmt++;
    }

    va_end(args);
    return printed_chars;
}

int main() {
    int a = 10;
    double b = 3.14;
    char c = 'X';

    int printed = my_printf("Integer: %d, Float: %f, Char: %c\n", a, b, c);
    printf("Total characters printed: %d\n", printed);

    return 0;
}
