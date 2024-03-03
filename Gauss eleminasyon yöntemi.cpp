#include <stdio.h>
#include <conio.h>
#include <math.h>
void printMatrix(float mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Matrisin tersini hesaplamak i�in Gauss-Jordan eliminasyonu
void inverseMatrix(float A[3][3], float result[3][3]) {
    // Birim matrisi olu�tur
    float I[3][3] = {{1, 0, 0},
                     {0, 1, 0},
                     {0, 0, 1}};

    // Verilen matris ve birim matrisi birle�tir
    float temp[3][6];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = A[i][j];
            temp[i][j + 3] = I[i][j];
        }
    }

    // Gauss-Jordan eliminasyonu
    for (int i = 0; i < 3; i++) {
        // Birinci ge�i�: Diagonalde 1 yapma
        float pivot = temp[i][i];
        for (int j = 0; j < 6; j++) {
            temp[i][j] /= pivot;
        }

        // �kinci ge�i�: Diagonal d���ndaki elemanlar� s�f�rlama
        for (int k = 0; k < 3; k++) {
            if (k != i) {
                float factor = temp[k][i];
                for (int j = 0; j < 6; j++) {
                    temp[k][j] -= factor * temp[i][j];
                }
            }
        }
    }

    // Sonu� matrisine atama
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = temp[i][j + 3];
        }
    }
}

int main() {
    float A[3][3] = {{1, 2, -1},
                     {3, 8, 2},
                     {4, 9, -1}};

    float result[3][3];

    // Matrisin tersini hesapla
    inverseMatrix(A, result);

    // Matrisi ve tersini ekrana yazd�r
    printf("Original Matrix A:\n");
    printMatrix(A);

    printf("Inverse Matrix A:\n");
    printMatrix(result);

    return 0;
}
