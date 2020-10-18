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

int BlobCount(int N, int M, int r, int c, int col, int* dataToBeRead)
{
	if (r < 0 || r >= N || c < 0 || c >= M)
		return 0;
	if (*(dataToBeRead + r * col + c) == ' ')
		return 0;
	if (*(dataToBeRead + r * col + c) == NULL) {
		return 0;
	}
	else
	{
		*(dataToBeRead + r * col + c) = ' ';
		//((data + i) + j)
		return (1 + BlobCount(N, M, r, c - 1, col, dataToBeRead) + BlobCount(N, M, r, c + 1, col, dataToBeRead) +
			BlobCount(N, M, r - 1, c, col, dataToBeRead) + BlobCount(N, M, r + 1, c, col, dataToBeRead));
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
		int* dataToBeRead = (int*)malloc(row * col * sizeof(int));

		horNumbers(col);
		horWall(col);
		for (int i = 0; i < row; i++) {
			printf("%d|", i);
			for (int j = 0; j < col + 1; j++) {
				*(dataToBeRead + i * col + j) = fgetc(data);//get the character 1 by 1 and set to into 2D array
				printf("%c", *(dataToBeRead + i * col + j));

				if (j == col - 1) {
					printf("| %d", i);
				}//end-if
			}//end-for-inner
		}//end-for-outer 
		horWall(col);
		horNumbers(col);
		printf("\n");
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				numberPixel = BlobCount(row, col, i, j, col, dataToBeRead);
				if (numberPixel > 0)
				{
					blobCounter[numberBloob] = numberPixel;
					printf("\nBlob %d: %d", numberBloob, numberPixel);
					numberBloob++;
				}
			}
		}
	}
	fclose(data);
	printf("\n");
	system("pause");

}