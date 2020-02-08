#include <stdio.h>
#include <stdlib.h>

#define swap(type, i, j) {type t = i; i = j; j = t;}
#define M 20


void showMatrix(float a[][M], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) 
			printf("%g%s", a[i][j], " ");

		printf("\n");
	}
}

int toReducedRowEchelon(float a[][M], int n) {
	int i, j, k = 0, c, state = 0;
	float p = 0;

	for (i = 0; i < n; i++) {

		if (a[i][i] == 0) {
			c = 1;

			while (a[i + c][i] == 0 && (i + c) < n)
				c++;

			if ((i + c) == n) {
				state = 1;
				break;
			}

			for (j = i, k = 0; k <= n; k++) 
				swap(float, a[j][k], a[j+c][k])
		}

		for (j = 0; j < n; j++) {
			if (i != j) {
				p = a[j][i] / a[i][i];

				for (k = 0; k <= n; k++)
					a[j][k] = a[j][k] - (a[i][k]) * p;
			}
		}
	}

	return state;
}

void showResult(float a[][M], int n, int state) {
	printf("conclusion: ");

	if (state == 2)
		printf("infinite solutions exists\n");

	else if (state == 3)
		printf("no solution exists\n");

	else {
		printf("one solution\n");

		for (int i = 0; i < n; i++)
			printf("%g%s", a[i][n] / a[i][i], "\n");
	}
}

int checkState(float a[][M], int n, int state) {
	int i, j;
	float sum;
	state = 3;

	for (i = 0; i < n; i++) {
		
		sum = 0;
		for (j = 0; j < n; j++)
			sum = sum + a[i][j];

		if (sum == a[i][j])
			state = 2;
	}

	return state;
}

int main() {
	float a[M][M];
	int state = 0;
	printf("num of equations in matrix: ");
	int n = getchar() - '0';
	printf("\n");

	if (n <= 0) {
		printf("ValueError! Cannot be less than or equal to 0\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {

		printf("coefficient: %d & equation value is last: %d \n", i + 1, n + 1);
		for (int j = 0; j <=n; j++) {
			printf("a%d%d : ", i, j);
			scanf("%f", &a[i][j]);
		}

		printf("\n");
	}

	state = toReducedRowEchelon(a, n);

	if (state == 1)
		state = checkState(a, n, state);

	printf("matrix : \n");
	showMatrix(a, n);
	printf("\n");
	showResult(a, n, state);
	return 0;
}