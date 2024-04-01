#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern void daxpy_x86(long long int n, double A, double *vectorX, double *vectorY, double *vectorZ);

extern void daxpy_c(long long int n, double A, double* vectorX, double* vectorY, double* vectorZ);

int main() {

	// Length of vectors
	const long long int n = 1 << 20;
	const size_t ARRAY_SIZE = n * sizeof(double);

	printf("LENGTH OF VECTOR: %lld\n\n", n);

	double A = 2.0;

	// Declaration
	double* vectorX, * vectorY, * vectorZ;

	// Initialize
	vectorX = (double*)malloc(ARRAY_SIZE);
	vectorY = (double*)malloc(ARRAY_SIZE);
	vectorZ = (double*)malloc(ARRAY_SIZE);

	// Error handling
	if (vectorX == NULL || vectorY == NULL || vectorZ == NULL) {
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

	// Call the function
	daxpy_x86(n, A, vectorX, vectorY, vectorZ);


	printf("---OUTPUT FOR x86-64---\n");
	// Display the first ten elements
	printf("Z --> ");
	if (n > 10) {
		for (int i = 0; i < 10; i++) {
			printf("%.2f, ", vectorZ[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 0; i < n; i++) {
			printf("%.2f, ", vectorZ[i]);
		}
		printf("\n");
	}



	// Free memory allocated 
	free(vectorX);
	free(vectorY);
	free(vectorZ);


	
	return 0;
}

