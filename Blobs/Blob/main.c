#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

	void fetchRowCol(char str[] , int *size) {
		int i = 0;
		char* token = strtok(str, " ");// fetch first token 
		while (token != NULL) {
			size[i] = atoi(token);//put the tokens into array
			i++;
			token = strtok(NULL, " ");
		}
	}


void main() {
	FILE* data;
	int err = fopen_s(&data, "blobs1.txt", "r");
	char dataToBeRead[SIZE][SIZE];
	int i = 0;
	char arr[SIZE];
	char* str;
	int* size[2];

	if (data == NULL)
	{
		printf("Test.c file failed to open.");
	}
	else
	{
		str = fgets(arr, 300, data); //fetch the first line of file in order to reach row and columns of 2D Array.
		fetchRowCol(str, &size); // throw the string which is include first line with first index of adress of size array 
		int row = size[0];
		int col = size[1];
		printf("row:%d\ncol:%d\n", row, col);

		for (int i = 0; i < row; i++) {
			printf("%d|", i);
			for (int j = 0; j < col+1; j++) {
				
				
				
					dataToBeRead[i][j] = fgetc(data);
					printf("%c", dataToBeRead[i][j]);
				

			}
				
	

		}
	}
		fclose(data);			   
		printf("\n");			   
		system("pause");
	
}
//dataToBeRead[l][k] = fgetc(data);
//printf("%c", dataToBeRead[l][k]);