#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 20

int main() {
    int n;
    float A[MAX_N][MAX_N], E[MAX_N][MAX_N], C[MAX_N][MAX_N], b[MAX_N], result[MAX_N];

    printf("Enter max size of square matrix (1-%d): ", MAX_N);
    scanf("%d", &n);
	if (n < 1 || n > MAX_N) {
		printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_N);
		return 1;
	}

    srand(time(NULL));

    // Filling matrix A
    printf("Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            printf("%5.1f ", A[i][j]);
        }
        printf("\n");
    }

    // Filling vector b
    printf("Vector b:\n");
    for (int i = 0; i < n; i++) {
        b[i] = rand() % 10;
        printf("%5.1f ", b[i]);
    }
    printf("\n");

    // Identity matrix E
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            E[i][j] = (i == j) ? 1 : 0;

    // C = A - E
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - E[i][j];

    // result = C * b
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++)
            result[i] += C[i][j] * b[j];
    }

    printf("Result (A-E)*b:\n");
    for (int i = 0; i < n; i++)
        printf("%8.2f\n", result[i]);

    return 0;
}