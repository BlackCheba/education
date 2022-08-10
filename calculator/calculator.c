#include <stdio.h>
#include <math.h>
#include <locale.h>

double print(double v);

int main() {

    setlocale(0, "");
    setlocale(LC_NUMERIC, "English");

    double pervoe, vtoroe, result;
    char oper;
    int check = 0;

    wprintf(L"'+' - сложение\n'-' - вычитание\n'*' - умножение\n'/' - деление\n'^' - степень\n");

    wprintf(L"Введите первое число:\n");
    if (!wscanf(L"%lf", &pervoe)) {
        printf("Error: ID 1");
        check = -1;
    }

    if (!check)
    
    wprintf(L"Введите необходимое действие:\n");
    do {
        if (!check && !scanf("%c", &oper)) {
            printf("Error: ID 2");
            check = -1;
        }
    } while (!check && (oper == ' ' || oper == '\n'));

    if (!check)

    wprintf(L"Введите второе число:\n");
    if (!check && !scanf("%lf", &vtoroe)) {
        printf("Error: ID 3");
        check = -1;
    }

    if(!check)
    
    switch(oper) {
        case '+' :
        result = pervoe + vtoroe;
        break;

        case '-' :
        result = pervoe - vtoroe;
        break;

        case '*' :
        result = pervoe * vtoroe;
        break;

        case '/' :
        result = pervoe / vtoroe;
        break;

        case '^' :
        result = pow(pervoe, vtoroe);
        break;

        case '=':
        check = -1;
        break;

        default :
        printf("Error: ID 4");
        check = -1;
        break;
    }
   
    if (!check) {
    

    print(pervoe);
    printf(" %c ", oper);
    print(vtoroe);
    printf(" = ");
    print(result);
    printf("\n");
    }

    return 0;
}

double print (double v) {
    int caret = 1000000;
    char p[6] = { '%', '.', 'N', 'l', 'f', '\0' };

    while (caret != 1 && !(((int)(v * (double)caret)) % 10)) {
        caret /= 10;
    }

    switch (caret) {

        case 1000000:
        p[2] = '6';
        break;

        case 100000:
        p[2] = '5';
        break;

        case 10000:
        p[2] = '4';
        break;

        case 1000:
        p[2] = '3';
        break;

        case 100:
        p[2] = '2';
        break;

        case 10:
        p[2] = '1';
        break;

        case 1:
        p[2] = '0';
        break;
    }
    
    printf(p, v);

    return 0;
}