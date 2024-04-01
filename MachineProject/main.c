#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern void daxpy_x86(long long int n, double A, double *vectorX, double *vectorY, double *vectorZ);

extern void daxpy_c(long long int n, double A, double* vectorX, double* vectorY, double* vectorZ);

int main() {

	// For getting time
	int begin, end;
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
	for (int j = 0; j < loop; j++) {
		begin = clock();
		daxpy_x86(n, A, vectorX, vectorY, vectorZ1);
		end = clock();

		time_taken = ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
		elapsed_time += time_taken;
	}

	average_time = elapsed_time / loop;

	printf("Average time: %.6f ms (%d iterations)\n\n", average_time, loop);

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
	begin = 0, end = 0, time_taken = 0, elapsed_time = 0, average_time = 0; 
	
	for (int j = 0; j < loop; j++) {
		begin = clock();
		daxpy_c(n, A, vectorX, vectorY, vectorZ2);
		end = clock();

		time_taken = ((double)(end - begin)) * 1e3 / CLOCKS_PER_SEC;
		elapsed_time += time_taken;
	}

	average_time = elapsed_time / loop;

	printf("Average time: %.6f ms (%d iterations)\n\n", average_time, loop);

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

	printf("\nACCURACY TEST\n");

	for (int i = 0; i < n; i++) {
		if (vectorZ1[i] != vectorZ2[i]) {
			check = 0;
		}
	}

	if (check != 0) {
		printf("All elements are the same for both vectors. Thus, both C and x86-64 functions share the same results");
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

