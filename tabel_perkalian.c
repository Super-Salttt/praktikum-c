// tabel_perkalian.c
#include <stdio.h>

int main() {
    int n;
    int result;
    
    printf("Masukkan angka untuk tabel perkalian: ");
    result = scanf("%d", &n);
    
    if (result != 1) {
        printf("Error: Input tidak valid. Masukkan bilangan bulat.\n");
        return 1;
    }
    
    if (n == 0) {
        printf("Peringatan: Perkalian dengan 0 hasilnya selalu 0.\n");
    }

    printf("\n=== Tabel Perkalian %d ===\n", n);
    for (int i = 1; i <= 10; i++) {
        printf("%2d x %2d = %4d\n", n, i, n * i);
    }
    printf("========================\n\n");
    
    return 0;
}