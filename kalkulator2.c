#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    double a, b, result;
    char op;
    char input[100];

    printf("Kalkulator C (Ketik 'q' untuk keluar)\n");

    while (1) {
        printf("\nMasukkan operasi (format: 3 + 4): ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        
        // Remove CR/LF from Windows input
        input[strcspn(input, "\r\n")] = 0;

        // Trim leading/trailing whitespace
        char *trimmed = input;
        while (*trimmed && isspace((unsigned char)*trimmed)) trimmed++;
        char *end = trimmed + strlen(trimmed);
        while (end > trimmed && isspace((unsigned char)*(end - 1))) *--end = '\0';

        if (*trimmed == '\0') continue;
        
        // Check for quit
        if (strcmp(trimmed, "q") == 0) break;
        
        // Parse the input
        if (sscanf(trimmed, "%lf %c %lf", &a, &op, &b) != 3) {
            printf("Input tidak valid\n");
            continue;
        }

        switch (op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': 
                if (b == 0) { printf("Error: Div by 0\n"); continue; }
                result = a / b; break;
            default: printf("Operator salah\n"); continue;
        }
        printf("Hasil: %.6g\n", result);
    }
    return 0;
}