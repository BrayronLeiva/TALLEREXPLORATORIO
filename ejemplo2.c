#include <stdio.h>

int multiplicar(int a, int b) {
    int resultado = 0;
    int negativo = (a < 0) ^ (b < 0); // Verifica si el resultado debe ser negativo
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;

    while (b > 0) {
        if (b & 1) // Si el bit menos significativo de b es 1, suma a al resultado
            resultado += a;
        a <<= 1; // Multiplica a por 2
        b >>= 1; // Divide b por 2
    }

    return negativo ? -resultado : resultado;
}

int main() {
    int x, y;
    printf("Ingrese dos numeros: ");
    scanf("%d %d", &x, &y);

    printf("Resultado: %d\n", multiplicar(x, y));
    return 0;
}
