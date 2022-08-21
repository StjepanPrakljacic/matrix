#include "function.h"

extern FILE* stream;


int matrixInitialize(MATRIX** matrixInstance, int rowSize, int columnSize)
{
	int rowCount;
	*matrixInstance = (MATRIX*)malloc(sizeof(MATRIX));
	if (*matrixInstance == NULL) return -1;

	(*matrixInstance)->data = (int**)malloc(rowSize * sizeof(int*));
	if ((*matrixInstance)->data == NULL) return -1;

	for (rowCount = 0; rowCount < rowSize; rowCount++)
	{
		(*matrixInstance)->data[rowCount] = (int*)malloc(columnSize * sizeof(int));
		if ((*matrixInstance)->data[rowCount] == NULL) return -1;
	}
	(*matrixInstance)->rowSize = rowSize;
	(*matrixInstance)->columnSize = columnSize;
	return 0;
}
static bool notInitialized(MATRIX* matrixInstance)
{
	if (matrixInstance == NULL)
		return true;
	return false;
}

int inputMatrix(MATRIX* matrixInstance)
{
	int rowCount, columnCount;
	if (notInitialized(matrixInstance)) return -1;
	for (rowCount = 0; rowCount < matrixInstance->rowSize; rowCount++)
	{
		for (columnCount = 0; columnCount < matrixInstance->columnSize; columnCount++)
		{
			 fscanf(stream, "%d", &matrixInstance->data[rowCount][columnCount]);
		}
	}
	return 0;
}

int clearMatrix(MATRIX* matrixInstance)
{
	int rowCount, columnCount;
	if (notInitialized(matrixInstance)) return -1;
	for (rowCount = 0; rowCount < matrixInstance->rowSize; rowCount++)
	{
		for (columnCount = 0; columnCount < matrixInstance->columnSize; columnCount++)
		{
			matrixInstance->data[rowCount][columnCount] = 0;
		}
	}
	return 0;
}

int deleteMatrix(MATRIX** matrixInstance)
{
	int rowCount;
	if (notInitialized(*matrixInstance)) return -1;
	for (rowCount = 0; rowCount < (*matrixInstance)->rowSize; rowCount++)
	{
		free((*matrixInstance)->data[rowCount]);
	}
	free(*matrixInstance);
	*matrixInstance = NULL;
	return 0;
}


void printMatrix(MATRIX* matrixInstance)
{
	int rowCount, columnCount;
	if (notInitialized(matrixInstance)) exit(EXIT_FAILURE);
	for (rowCount = 0; rowCount < matrixInstance->rowSize; rowCount++)
	{
		printf("\t");
		for (columnCount = 0; columnCount < matrixInstance->columnSize; columnCount++)
		{
			printf("%d ", matrixInstance->data[rowCount][columnCount]);
		}
		printf("\n");
	}
}
