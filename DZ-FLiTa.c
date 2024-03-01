#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Функция addstring используется для добавления символа в конец строки
void addstring(char *str, char c) {
    int len = strlen(str);
    str[len] = c;        // Добавляет символ в конец строки
    str[len + 1] = '\0'; // Конец строки
}

// Функция fun_binary преобразует целое число в двоичное и сохраняет его в строке
void fun_binary(int x, char *str) {
    int d;
    while (x != 0) {
        d = x % 2;                    // Получите остаток при делении на 2
        addstring(str, d + '0');      // Добавляет остаток к строке в виде символов
        x /= 2;                       // Разделите число на 2
    }
    int len = strlen(str);
    if (len == 0) {
        addstring(str, '0'); // Если строка пуста, добавьте символ «0»
    }
    // Переверните строку
    for (int i = 0, j = len - 1; i <= j; i++, j--) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

int main() {
    int a[100], n, e;

    // Введите количество элементов в массиве, попросите пользователя ввести повторно, если оно неверно
    do {
        e = 0;
        printf("How many numbers do you want to input (1 < n < 100): ");
        e = scanf("%d", &n);
        while (getchar() != '\n'); // Прочитайте и отбросьте оставшиеся символы в буфере
    } while (e == 0 || (n <= 1 || n >= 100)); // Повторите, если введенные данные недействительны

    // Введите значение для каждого элемента массива, попросите ввести его повторно, если оно неверно
    for (int i = 0; i < n; i++) {
        int inputSuccess = 0;
        do {
            printf("Input value for a[%d]: ", i);
            inputSuccess = scanf("%d", &a[i]);
            while (getchar() != '\n'); // Прочитайте и отбросьте оставшиеся символы в буфере
        } while (inputSuccess == 0); // Повторите, если ввод неверен.
    }

    // Распечатайте введенный массив
    printf("Your array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    char d[100][100];
    // Преобразуйте каждый элемент массива в двоичную форму и сохраните его в двумерном массиве d
    for (int i = 0; i < n; i++) {
        d[i][0] = '\0';     // Инициализировать пустую строку
        fun_binary(a[i], d[i]); // Преобразуйте число в двоичный формат и сохраните его в d[i]
    }

    // Распечатайте массив в двоичном виде
    printf("\nYour binary array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", d[i]);
    }

    return 0;
}
