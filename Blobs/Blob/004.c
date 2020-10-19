#include <stdio.h>
#include <stdlib.h>
#define SIZE 300

void fetchRowCol(char str[], int* size) {
	int i = 0;
	char* token = strtok(str, " ");// fetch first token 
	while (token != NULL) {
		size[i] = atoi(token);//put the tokens into array
		i++;
		token = strtok(NULL, " ");
	}
}
void horNumbers(int col) {
	int number;
	printf("\n  ");
	for (int i = 0; i < col; i++)
	{
		number = i % 10;
		printf("%d", number);
	}
}
void horWall(int col) {
	printf("\n ");
	printf("+");
	for (int i = 0; i < col; i++)
	{
		printf("-");
	}
	printf("+");
	printf("\n");
}

int BlobPixelCounter(int N, int M, int r, int c, int* dataToBeRead)
{
	if (r < 0 || r >= N || c < 0 || c >= M)
		return 0;
	if (*(dataToBeRead + r * M + c) == ' ')
		return 0;
	if (N == 0 || N == NULL || M == 0 || M == NULL) {
		return 0;
	}
	if (*(dataToBeRead + r * M + c) == NULL) {
		return 0;
	}
	else
	{
		*(dataToBeRead + r * M + c) = ' ';
		return (1 + BlobPixelCounter(N, M, r, c - 1, dataToBeRead) + BlobPixelCounter(N, M, r, c + 1, dataToBeRead) +
			BlobPixelCounter(N, M, r - 1, c, dataToBeRead) + BlobPixelCounter(N, M, r + 1, c, dataToBeRead));
	}
}

int centerOfMassX(int N, int M, int r, int c, int* dataToBeRead, int numberOfPixel) {
	if (r < 0 || r >= N || c < 0 || c >= M)
		return 0;
	if (*(dataToBeRead + r * M + c) == ' ')
		return 0;
	if (N == 0 || N == NULL || M == 0 || M == NULL) {
		return 0;
	}
	if (*(dataToBeRead + r * M + c) == NULL) {
		return 0;
	}
	else
	{	
		*(dataToBeRead + r * M + c) = ' ';
		return ( (r / numberOfPixel) + centerOfMassX(N, M, r, c - 1, dataToBeRead, numberOfPixel) + centerOfMassX(N, M, r, c + 1, dataToBeRead, numberOfPixel) +
			centerOfMassX(N, M, r - 1, c, dataToBeRead, numberOfPixel) + centerOfMassX(N, M, r + 1, c, dataToBeRead, numberOfPixel));

	}
	
}

void main() {
	FILE* data;
	int err = fopen_s(&data, "blobs1.txt", "r");
	int i = 0;
	char arr[SIZE];
	char* str;
	int* size[2];
	int numberPixel;
	int numberBloob = 0;
	int blobCounter[SIZE];
	int X;
	int Y;
	if (data == NULL)
	{
		printf("Test.c file failed to open.");
	}
	else
	{
		str = fgets(arr, 300, data); //fetch the first line of file in order to reach row and columns of 2D Array which is the file.
		fetchRowCol(str, &size); // throw the string which is include first line with first index of adress of size array 
		int row = size[0];// assign the value of row to variable
		int col = size[1];//assign the value of column to variable 
		int* dataToBeRead = (int*)malloc(row * col * sizeof(int));
		int* tempData = (int*)malloc(row * col * sizeof(int));

		horNumbers(col);//Making horizontal Counter  to top of table
		horWall(col);//Making horizontal Border to to top of table
		for (int i = 0; i < row; i++) {
			printf("%d|", i);//Making vertical border to left side of table
			for (int j = 0; j < col + 1; j++) {
				*(dataToBeRead + i * col + j) = fgetc(data);//get the character 1 by 1 and set to into 2D dynamic allacoted array
				printf("%c", *(dataToBeRead + i * col + j));//print to log 1 by 1 character from 2D dynamic allacoted array 
				if (j == col - 1) {
					printf("| %d", i);//Making vertical border to right side of table
				}//end-if
			}//end-for-inner
		}//end-for-outer 
		horWall(col);////Making horizontal Counter  to top of table
		horNumbers(col);//Making horizontal Border to bottom of table

		printf("\n");
		//Copying the matrix to another temp matrix
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				*(tempData + i * col + j) = *(dataToBeRead + i * col + j);
			}
		}

		//Testing Copy
		/*for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				printf("%c",*(tempData + i * col + j));
			}
			printf("\n");
		}*/


		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				numberPixel = BlobPixelCounter(row, col, i, j, dataToBeRead);
				if (numberPixel > 0)
				{
				    X = centerOfMassX(row, col, i, j, tempData, numberPixel);
					if (X > 0) {
					  blobCounter[numberBloob] = numberPixel;
					  printf("\nBlob %d,  Number of pixel:%d, X:%d", numberBloob, numberPixel, X);
					  numberBloob++;

					}
				}
			}
		}


		/*for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
			
				 X = centerOfMassX(row, col, i, j, tempData ,blobCounter[i]);
				if (X > 0)
				{
					printf("center of Mass X :%d", X);
					
				}
			}
		}*/


		
	}
	fclose(data);
	printf("\n");
	system("pause");

}