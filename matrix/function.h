/*
 * functions.h
 *  Created on: Aug 21, 2022
 *      Author: Stjepan Prakljacic
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

typedef struct matrix {
	int rowSize;
	int columnSize;
	int** data;
}MATRIX;

/*
* Function matrixInitialize()
* Description: The function will allocate memory for the passed instance of the matrix and will set all values ​​of the passed instance with respect to the passed values 
*	@param -  matrix instance that can be NULL
*	@param -  User defined number of rows
*	@param -  User defined number of colums
* Returns: Succes status 
*/
int matrixInitialize(MATRIX** matrixInstance, int rowSize, int columnSize);

/*
* Function inputMatrix()
* Description: The function will read data from matrixData.txt and it will fill the matrix
*	@param -  matrix instance that can not be NULL
* Returns: Succes state
*/

int inputMatrix(MATRIX* matrixInstance);

/*
* Function printMatrix()
* Description: The function will print all the data values  for the passed instance of the matrix
*	@param -  matrix instance that can not be NULL
* Returns: void
*/

void printMatrix(MATRIX* matrixInstance);

/*
* Function clearMatrix()
* Description: The function will set data values for the passed instance of the matrix on '0'
*	@param -  matrix instance that can not be NULL
* Returns: Succes state
*/
int clearMatrix(MATRIX* matrixInstance);

/*
*Function deleteMatrix()
* Description: The function will deallocate memory for the passed instance of the matrix
* @param - matrix instance that can not be NULL
* Returns: Succes state
*/
int deleteMatrix(MATRIX** matrixInstance);


#endif // !FUNCTIONS_H