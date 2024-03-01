#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void addstring(char *str, char c) {
    int len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
}

void fun_binary(int x, char *str) {
    int d;
    while (x != 0) {
        d = x % 2;
        addstring(str, d + '0');
        x /= 2;
    }
    int len = strlen(str);
    if (len == 0) {
        addstring(str, '0');
    }
    for (int i = 0, j = len - 1; i <= j; i++, j--) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

int main() {
    int a[100], n, e;

   do {
    e = 0;
    printf("How many numbers do you want to input (1 < n < 100): ");
    e = scanf("%d", &n);
    while (getchar() != '\n');
} while (e == 0 || (n <= 1 || n >= 100));

   for (int i = 0; i < n; i++) {
        int inputSuccess = 0;
        do {
            printf("Input value for a[%d]: ", i);
            inputSuccess = scanf("%d", &a[i]);
            while (getchar() != '\n');
        } while (inputSuccess == 0);
    }
    printf("Your array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    char d[100][100];
    for (int i = 0; i < n; i++) {
        d[i][0] = '\0';
        fun_binary(a[i], d[i]);
    }

    printf("\nYour binary array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", d[i]);
    }

    return 0;
}

