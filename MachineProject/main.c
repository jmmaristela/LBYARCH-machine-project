#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern void daxpy(long long int n, double A, double *X, double* Y, double* Z);

int main() {

	// Length of vectors
	const long long int n = 3;
	const size_t ARRAY_SIZE = n * sizeof(double);

	const double A = 2.0; // Scalar variable A

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

	// sample only
	vectorX[0] = 1.0;
	vectorX[1] = 2.0;
	vectorX[2] = 3.0;

	vectorY[0] = 11.0;
	vectorY[1] = 12.0;
	vectorY[2] = 13.0;

	for (int i = 0; i < n; i++) {
		vectorZ[i] = 0.0;
	}

	printf("%.2f, ", vectorX[0]);
	printf("%.2f, ", vectorX[1]);
	printf("%.2f, ", vectorX[2]);

	printf("%.2f, ", vectorY[0]);
	printf("%.2f, ", vectorY[1]);
	printf("%.2f, ", vectorY[2]);

	daxpy(n, A, vectorX, vectorY, vectorZ);

	printf("Z: ");
	for (int i = 0; i < n; i++) {
		printf("%.2f, ", vectorZ[i]);
	}
	printf("\n");
	
	
	return 0;
}

