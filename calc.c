#include <stdio.h>
#include <string.h>
int main(void) {
        double a, b, result;
        char op;
        char input[100];


        printf("masukkan operasi (format: 3,5 + 4,2): ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("input tidak valid\n");
            return 1;
        }
        // Replace commas with dots for decimal parsing
        for (char *p = input; *p; p++) {
            if (*p == ',') *p = '.';
        }
        if (sscanf(input, "%lf %c %lf", &a, &op, &b) != 3) {
            printf("input tidak valid\n");
            return 1;
        }

        switch (op) {
            case '+' : result = a + b;break;
            case '-' : result = a - b;break;
            case '*' : result = a * b;break;
            case '/' :
                if (b == 0) {
                    printf("error: pembagian dengan nol\n");
                    return 1;
                }
                result = a / b;
                break;
            default:
                printf("operator tidak dikenali\n");
                return 1;
        }
    
    printf("%.6g %c %.6g = %.6g\n", a, op, b, result);
        return 0;
}