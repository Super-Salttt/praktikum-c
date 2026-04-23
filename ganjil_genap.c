// ganjil_genap.c
#include <stdio.h>

int main() {
    int angka;
    int result;
    
    printf("Masukkan sebuah bilangan: ");
    result = scanf("%d", &angka);
    
    if (result != 1) {
        printf("Error: Input tidak valid. Masukkan bilangan bulat.\n");
        return 1;
    }

    if (angka % 2 == 0) {
        printf("%d adalah bilangan GENAP\n", angka);
    } else {
        printf("%d adalah bilangan GANJIL\n", angka);
    }
    return 0;
}