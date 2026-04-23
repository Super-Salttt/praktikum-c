// nilai_mahasiswa.c
#include <stdio.h>

#define MAX_MAHASISWA 100

// Fungsi 1: Menentukan grade dari nilai
char tentukanGrade(int nilai) {
    if (nilai >= 85) return 'A';
    else if (nilai >= 70) return 'B';
    else if (nilai >= 55) return 'C';
    else if (nilai >= 40) return 'D';
    else return 'E';
}

// Fungsi 2: Menampilkan keterangan grade
void tampilkanKeterangan(char grade) {
    switch(grade) {
        case 'A': printf("Keterangan: Sangat Baik\n"); break;
        case 'B': printf("Keterangan: Baik\n"); break;
        case 'C': printf("Keterangan: Cukup\n"); break;
        case 'D': printf("Keterangan: Kurang\n"); break;
        case 'E': printf("Keterangan: Sangat Kurang\n"); break;
    }
}

// Fungsi 3: Clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fungsi 4: Hitung statistik
void hitungStatistik(int nilai[], int jumlah) {
    int total = 0, max = nilai[0], min = nilai[0];
    float rata_rata;
    
    for (int i = 0; i < jumlah; i++) {
        total += nilai[i];
        if (nilai[i] > max) max = nilai[i];
        if (nilai[i] < min) min = nilai[i];
    }
    
    rata_rata = (float)total / jumlah;
    
    printf("\n========================================\n");
    printf("STATISTIK NILAI MAHASISWA\n");
    printf("========================================\n");
    printf("Total Mahasiswa  : %d\n", jumlah);
    printf("Nilai Tertinggi  : %d\n", max);
    printf("Nilai Terendah   : %d\n", min);
    printf("Rata-rata Nilai  : %.2f\n", rata_rata);
    printf("========================================\n\n");
}

int main() {
    int jumlah, nilai[MAX_MAHASISWA];
    char grade;
    int result;

    printf("=== PROGRAM NILAI MAHASISWA ===\n\n");
    printf("Masukkan jumlah mahasiswa: ");
    result = scanf("%d", &jumlah);
    
    if (result != 1) {
        printf("Error: Input tidak valid. Masukkan bilangan bulat.\n");
        return 1;
    }
    
    if (jumlah <= 0 || jumlah > MAX_MAHASISWA) {
        printf("Error: Jumlah mahasiswa harus antara 1-%d.\n", MAX_MAHASISWA);
        return 1;
    }
    
    clearInputBuffer();

    // Perulangan untuk banyak mahasiswa
    for (int i = 0; i < jumlah; i++) {
        printf("\n--- Mahasiswa ke-%d ---\n", i + 1);
        printf("Masukkan nilai (0-100): ");
        
        result = scanf("%d", &nilai[i]);
        
        if (result != 1) {
            printf("Error: Input tidak valid. Masukkan bilangan bulat.\n");
            clearInputBuffer();
            i--; // Ulangi input untuk mahasiswa ini
            continue;
        }

        // Validasi input
        if (nilai[i] < 0 || nilai[i] > 100) {
            printf("Error: Nilai tidak valid! Harus 0-100\n");
            i--; // Ulangi input untuk mahasiswa ini
            continue;
        }

        grade = tentukanGrade(nilai[i]);
        printf("Nilai: %d | Grade: %c\n", nilai[i], grade);
        tampilkanKeterangan(grade);
    }

    // Tampilkan statistik
    hitungStatistik(nilai, jumlah);
    
    printf("Selesai memproses %d mahasiswa.\n\n", jumlah);
    
    return 0;
}