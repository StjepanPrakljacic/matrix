#include "function.h"

FILE* stream = NULL;

int main()
{
	MATRIX *matrxInstance = NULL;
	int status;
	
	stream = fopen("matrixData.txt", "r");

	if (stream == NULL) {
		perror("Opening stream");
		exit(EXIT_FAILURE);
	}
	else {
		printf("Stream successfully opened!\n");
	}

	status = matrixInitialize(&matrxInstance, 4, 4);
	printf("Matrix initialize success: %s\n", status < 0 ? "false" : "true");
	if (status < 0)
	{
		fprintf(stderr, "Allocation error");
		exit(EXIT_FAILURE);
	}

	status = inputMatrix(matrxInstance);
	printf("Matrix input success: %s\n", status < 0 ? "false" : "true");
	if (status < 0)
	{
		fprintf(stderr, "Input error");
		exit(EXIT_FAILURE);
	}

	printMatrix(matrxInstance);

	status = clearMatrix(matrxInstance);
	printf("Matrix clear success: %s\n", status < 0 ? "false" : "true");
	if (status < 0)
	{
		fprintf(stderr, "Clear error");
		exit(EXIT_FAILURE);
	}

	printMatrix(matrxInstance);

	status = deleteMatrix(&matrxInstance);
	printf("Matrix delete success: %s\n", status < 0 ? "false" : "true");
	if (status < 0)
	{
		fprintf(stderr, "Delete error");
		exit(EXIT_FAILURE);
	}
	if (fclose(stream) == 0) {
		printf("Stream successfully closed!\n");
	}

	return 0;
}