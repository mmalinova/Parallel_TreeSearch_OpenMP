#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int* A, int n, int tos);

int main(){

	int number = 0, iter = 0, find;
	int* Arr;

	Arr = (int *)malloc(number * sizeof(int));
	scanf_s("%d", &number);

	for (; iter<number; iter++){
		scanf_s("%d", &Arr[iter]);
	}

	scanf_s("%d", &find);
	printf("\nTo find: %d\n", find);

	int indx = linearSearch(Arr, number, find);

	if (indx == -1)
		printf("Not found");
	else
		printf("Found at %d\n", indx);

	return 0;
}

int linearSearch(int* A, int n, int tos){
	int foundat = -1;

#pragma omp parallel for
	for (int iter = 0; iter < n; iter++){
		if (A[iter] == tos)
			foundat = iter + 1;
	}
	return foundat;
}