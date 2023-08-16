#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
    int curNum;
    int sum = 0; // Инициализираме променливата за сумата
    
    while (read(STDIN_FILENO, &curNum, sizeof(curNum)) == sizeof(curNum)) {
        sum += curNum; // Натрупваме текущото число към сумата
    }
    
    printf("Sum: %d\n", sum); // Извеждаме общата сума на стандартния изход
    
    return 0;
    
}