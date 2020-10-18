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

int BlobCount(int *dataToBeRead, int N,int M, int r, int c)
{
	if (r < 0 || r >= N || c < 0 || c >= M) {
		return 0;
	}
	if (*(dataToBeRead) == ' ') {
		return 0;
	}
	if (*(dataToBeRead) == NULL) {
		return 0;
	}
	else
	{	
		*(dataToBeRead) = ' ';
		//*(*(data + i) + j)
		//printf("adress:%d\n", datatoberead );
}       return (1 + BlobCount(((dataToBeRead + r) + c - 1 ), N, M, r, c - 1 ) + BlobCount(((dataToBeRead + r) + c + 1) , N, M, r, c + 1) + BlobCount(((dataToBeRead +  (r - 1) ) + c) , N, M, r - 1, c) + BlobCount(((dataToBeRead + ( r + 1) ) + c), N, M, r + 1, c));
		
}

int changeUp(int* dataToBeRead, int r, int c, int N, int M) {
	if (r -1 < 0 || r >= N || c < 0 || c >= M ) {
		return 0;
	}
	if ( *dataToBeRead == ' ') {
		return 0;
	}
	if ( dataToBeRead == NULL) {
		return 0;
	}
	return ((dataToBeRead + (r-1) * M) + c);
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
	char dataToBeRead[SIZE][SIZE];

	if (data == NULL)
	{
		printf("Test.c file failed to open.");
	}
	else
	{
		str = fgets(arr, 300, data); //fetch the first line of file in order to reach row and columns of 2D Array.
		fetchRowCol(str, &size); // throw the string which is include first line with first index of adress of size array 
		int row = size[0];// assign the value of row to variable
		int col = size[1];//assign the value of column to variable 
		
		horNumbers(col);
		horWall(col);
		for (int i = 0; i < row; i++) {
			printf("%d|", i);
			for (int j = 0; j < col + 1; j++) {
				dataToBeRead[i][j] = fgetc(data);//get the character 1 by 1 and set to into 2D array
				printf("%c", dataToBeRead[i][j]);
				if (j == col - 1) {
					printf("| %d", i);
				}//end-if
			}//end-for-inner
		}//end-for-outer 
		horWall(col);
		horNumbers(col);
		printf("\n");

	/*	for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				numberPixel = BlobCount(&dataToBeRead[i][j] , row , col, i, j);
				if (numberPixel > 0)
				{
					blobCounter[numberBloob] = numberPixel;
					printf("\nBlob %d: %d", numberBloob, numberPixel);
					numberBloob++;
				}

			}
		}*/


	/*	for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				printf("%d", (*(dataToBeRead + i) + j) );
				printf("---------------\n");
				printf("otelenms: %d", (*(dataToBeRead + i) + (j-1)));
				printf("\n");
			}
			printf("\n");
	}*/

	 	for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				printf("Adress of A[ %d ][ %d ] :%d\n ", i,j, &dataToBeRead[i][j]);
				int adressofUp = changeUp(&dataToBeRead[i][j], i, j, row ,col);
				if (adressofUp == 0) {
					printf("Adress of A[ %d ][ %d ] :%d\n", i, j, adressofUp);
				}
				else {
					printf("Adress of Up Cell A[%d][%d] : %d\n",i-1,j, adressofUp);

				}
				printf("\n");
			}
			printf("%d .Satir  \n" , i + 1);
	}

		
	}
	fclose(data);
	printf("\n");
	system("pause");

}