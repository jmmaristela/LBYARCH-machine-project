void daxpy_c(long long int n, double A, double* vectorX, double* vectorY, double* vectorZ) {
	
	int i;
	for (i = 0; i < n; i++) {
		// Implement formula for computation
		vectorZ[i] = A * vectorX[i] + vectorY[i];
	}
}