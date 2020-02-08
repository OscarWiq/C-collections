#include <stdio.h>
#define SIZE 10

#define swap(type, i, j) {type t = i; i = j; j = t;}

int partition(int a[], int low, int high) {
	int pivot = a[high], i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (a[j] < pivot) {
			i++;
			swap(int, a[i], a[j])
		}
	}

	swap(int, a[i + 1], a[high])
	return (i + 1);
}

void quickSort(int a[], int low, int high) {
	if (low < high) {
		int partitioningIndex = partition(a, low, high);

		quickSort(a, low, partitioningIndex - 1);
		quickSort(a, partitioningIndex + 1, high);
	}
}

void printArr(int a[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d%s", a[i], " ");
	printf("\n");
}

int main() {
	int a[SIZE];

	printf("fill a: \n");
	for (int i = 0; i < SIZE; i++)
		scanf("%d", &a[i]);

	int n = sizeof(a) / sizeof(a[0]);
	quickSort(a, 0, n - 1);
	printf("Sorted: ");
	printArr(a, n);
	return 0;
}