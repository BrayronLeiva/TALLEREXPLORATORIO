#include <stdio.h>

int esPotenciaDeDos(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (esPotenciaDeDos(num))
        printf("%d es una potencia de 2.\n", num);
    else
        printf("%d NO es una potencia de 2.\n", num);

    return 0;
}
