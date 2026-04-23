// luas_lingkaran.c
#include <stdio.h>
#include <math.h>

#define PI M_PI

// Fungsi untuk hitung luas lingkaran
float hitungLuasLingkaran(float jari_jari) {
    if (jari_jari < 0) {
        printf("Error: Jari-jari tidak boleh negatif!\n");
        return -1;
    }
    return PI * jari_jari * jari_jari;
}

// Fungsi untuk hitung keliling lingkaran
float hitungKelilingLingkaran(float jari_jari) {
    if (jari_jari < 0) {
        return -1;
    }
    return 2 * PI * jari_jari;
}

int main() {
    float r, luas, keliling;
    int result;
    
    printf("=== KALKULATOR LINGKARAN ===\n");
    printf("Masukkan jari-jari lingkaran (cm): ");
    result = scanf("%f", &r);
    
    if (result != 1) {
        printf("Error: Input tidak valid. Masukkan bilangan desimal.\n");
        return 1;
    }
    
    if (r < 0) {
        printf("Error: Jari-jari tidak boleh negatif!\n");
        return 1;
    }
    
    if (r == 0) {
        printf("Peringatan: Jari-jari 0 menghasilkan luas dan keliling 0.\n");
    }

    luas = hitungLuasLingkaran(r);
    keliling = hitungKelilingLingkaran(r);
    
    printf("\n--- HASIL PERHITUNGAN ---\n");
    printf("Jari-jari         : %.2f cm\n", r);
    printf("Diameter          : %.2f cm\n", r * 2);
    printf("Luas              : %.2f cm²\n", luas);
    printf("Keliling          : %.2f cm\n", keliling);
    printf("------------------------\n\n");
    
    return 0;
}