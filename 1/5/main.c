
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Програма для обчислення (A-E)*b
int main() {
	int N, i, j;
	printf("Введіть розмір квадратної матриці n: ");
	scanf("%d", &N);
	const int n = N;

	float A[n][n]; // Матриця A
	float E[n][n]; // Одинична матриця E
	float b[n];    // Вектор b
	float C[n][n]; // Матриця C = A - E
	float result[n]; // Результуючий вектор

	srand(time(NULL));

	// Генеруємо матрицю A та вектор b
	printf("Матриця A:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = rand() % 10; // випадкові числа 0-9
			printf("%5.1f ", A[i][j]);
		}
		printf("\n");
	}

	printf("Вектор b:\n");
	for (i = 0; i < n; i++) {
		b[i] = rand() % 10;
		printf("%5.1f ", b[i]);
	}
	printf("\n");

	// Створюємо одиничну матрицю E
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			E[i][j] = (i == j) ? 1 : 0;
		}
	}

	// Обчислюємо C = A - E
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = A[i][j] - E[i][j];
		}
	}

	// Множимо матрицю C на вектор b: result[i] = sum_j(C[i][j] * b[j])
	for (i = 0; i < n; i++) {
		result[i] = 0;
		for (j = 0; j < n; j++) {
			result[i] += C[i][j] * b[j];
		}
	}

	printf("Результат (A-E)*b:\n");
	for (i = 0; i < n; i++) {
		printf("%8.2f\n", result[i]);
	}

	// Пояснення:
	// 1. Вектор — це масив з n елементів (одновимірний).
	// 2. Матриця — це масив з n*n елементів (двовимірний).
	// 3. Одинична матриця має 1 на головній діагоналі, 0 — в інших місцях.
	// 4. Віднімання матриць — елементно: C[i][j] = A[i][j] - E[i][j].
	// 5. Множення матриці на вектор — скалярний добуток рядка матриці на вектор.

	return 0;
}
