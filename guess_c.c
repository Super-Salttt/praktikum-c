// guess_c.c - Modifikasi Tugas Pekan 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi buat baca best score dari file
int load_best_score() {
    FILE *f = fopen("best_score.txt", "r");
    if (f == NULL) return -1; // -1 artinya belum ada skor
    int score;
    fscanf(f, "%d", &score);
    fclose(f);
    return score;
}

// Fungsi buat simpan best score ke file
void save_best_score(int score) {
    FILE *f = fopen("best_score.txt", "w");
    if (f != NULL) {
        fprintf(f, "%d", score);
        fclose(f);
    }
}

int main(void) {
    int min = 1, max, level;
    int secret, guess, attempts = 0;
    int best_score = load_best_score();
    srand((unsigned) time(NULL));

    // Tampilkan best score kalau ada
    if (best_score != -1) {
        printf("Best Score saat ini: %d percobaan\n", best_score);
    }
    printf("------------------------------------\n");

    // Tambahan: Pilih Level
    printf("Pilih Level:\n");
    printf("1. Easy   (1-10)\n");
    printf("2. Medium (1-100)\n");
    printf("3. Hard   (1-1000)\n");
    printf("Pilihan 1/2/3: ");
    scanf("%d", &level);

    switch(level) {
        case 1:
            max = 10;
            break;
        case 2:
            max = 100;
            break;
        case 3:
            max = 1000;
            break;
        default:
            max = 100; // Default ke Medium jika input invalid
            printf("Input tidak valid. Menggunakan Level Medium (1-100)\n");
            break;
    }

    secret = rand() % (max - min + 1 ) + min;

    printf("Tebak angka antara %d sampai %d!\n", min, max);
    while (1) {
        printf("Masukkan tebakan: ");
        if (scanf("%d", &guess) != 1) {
            // clear invalid input
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Input tidak valid, coba lagi.\n");
            continue;
        }
        if (guess < min || guess > max) {
            printf("Angka harus antara %d dan %d!\n", min, max);
            continue;
        }
        attempts++;
        if (guess < secret) {
            printf("Terlalu kecil.\n");
        } else if (guess > secret) {
            printf("Terlalu besar.\n");
        } else {
            printf("Benar! Kamu menebak dalam %d percobaan\n", attempts);
            
            // Tambahan: Cek & simpan best score
            if (best_score == -1 || attempts < best_score) {
                printf("REKOR BARU! Skor %d disimpan ke best_score.txt\n", attempts);
                save_best_score(attempts);
            } else {
                printf("Best score masih %d percobaan\n", best_score);
            }
            break;
        }
    }
    return 0;
}