#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern void daxpy_x86(long long int n, double A, double* vectorX, double* vectorY, double* vectorZ);

extern void daxpy_c(long long int n, double A, double* vectorX, double* vectorY, double* vectorZ);

int main() {

	// For getting time
	//int begin, end;

	LARGE_INTEGER frequency;
	LARGE_INTEGER start;
	LARGE_INTEGER end;

	double time_taken = 0, elapsed_time = 0;
	double average_time = 0;

	// For accuracy check
	int check = 1;

	// Length of vectors
	const long long int n = 1 << 20;
	const size_t ARRAY_SIZE = n * sizeof(double);

	printf("LENGTH OF VECTOR: %lld\n\n", n);

	double A = 2.0;

	// Declaration
	double* vectorX, * vectorY, * vectorZ1, *vectorZ2;

	// Initialize
	vectorX = (double*)malloc(ARRAY_SIZE);
	vectorY = (double*)malloc(ARRAY_SIZE);

	vectorZ1 = (double*)malloc(ARRAY_SIZE);
	vectorZ2 = (double*)malloc(ARRAY_SIZE);

	// Error handling
	if (vectorX == NULL || vectorY == NULL || vectorZ1 == NULL || vectorZ2 == NULL) {
		printf("Memory allocation failed\n");
		return 1; 
	}

	// Store data inside vectors
	int count;
	double i, j;
	for (count = 0, i = 1.0, j = 11.0; count < n; count++, i++, j++) {
		vectorX[count] = i;
		vectorY[count] = j;
	}

	// Call the function to fill the cache 
	daxpy_x86(n, A, vectorX, vectorY, vectorZ1);

	printf("--- OUTPUT FOR x86-64 ---\n");

	
	int loop = 30;
	
	// Measure elapsed time
	QueryPerformanceFrequency(&frequency);
	for (int j = 0; j < 30; j++) {
		QueryPerformanceCounter(&start);
		daxpy_x86(n, A, vectorX, vectorY, vectorZ1);
		QueryPerformanceCounter(&end);

		elapsed_time += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	}

	average_time = elapsed_time / 30;

	printf("Average time: %.6f milliseconds (30 iterations)\n\n", average_time * 1000);
	

	// Display the first ten elements
	printf("Z --> ");
	if (n > 10) {
		for (int i = 0; i < 10; i++) {
			printf("%.2f, ", vectorZ1[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 0; i < n; i++) {
			printf("%.2f, ", vectorZ1[i]);
		}
		printf("\n");
	}

	// ------- DIVIDER ------- 
	
	// Call the function to fill the cache 
	daxpy_c(n, A, vectorX, vectorY, vectorZ2);

	printf("\n\n--- OUTPUT FOR C ---\n");

	// Initialize again
	time_taken = 0, elapsed_time = 0, average_time = 0; 
	
	// Measure elapsed time
	QueryPerformanceFrequency(&frequency);
	for (int j = 0; j < 30; j++) {
		QueryPerformanceCounter(&start);
		daxpy_c(n, A, vectorX, vectorY, vectorZ2);
		QueryPerformanceCounter(&end);

		elapsed_time += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	}

	average_time = elapsed_time / 30;

	printf("Average time: %.6f milliseconds (30 iterations)\n\n", average_time * 1000);

	printf("Z --> ");
	if (n > 10) {
		for (int i = 0; i < 10; i++) {
			printf("%.2f, ", vectorZ2[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 0; i < n; i++) {
			printf("%.2f, ", vectorZ2[i]);
		}
		printf("\n");
	}
	
	printf("\n\nACCURACY TEST\n");

	for (int i = 0; i < n; i++) {
		if (vectorZ1[i] != vectorZ2[i]) {
			check = 0;
		}
	}

	if (check != 0) {
		printf("All elements are the same for both vectors. Thus, both C and x86-64 functions share the same results\n\n\n");
	}
	else {
		printf("There is a difference...");
	}

	// Free memory allocated 
	free(vectorX);
	free(vectorY);
	free(vectorZ1);
	free(vectorZ2);


	return 0;
}
