#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

	int  *fetchRowCol(char str[], int a) {
		int *size[2];
		int i = 0;
		char* token = strtok(str, " ");// fetch first token , token= 10
		while (token != NULL) {
			size[i] = atoi(token);//put the first token into array, size[0] = 10
			i++;
			token = strtok(NULL, " ");
		}
		for (int i = 0; i < 2; i++)
		{
			printf("%d\n", size[i]);
		}
		if (a % 2 == 0) {
			return *size[0];
		}
		else
		{
			return *size[1];
		}
		
	}


void main() {
	FILE* data;
	int err = fopen_s(&data, "blobs1.txt", "r");
	char dataToBeRead[SIZE][SIZE];
	int i = 0;
	char arr[SIZE];
	char* str;
	int size[2];

	if (data == NULL)
	{
		printf("Test.c file failed to open.");
	}
	else
	{
		str = fgets(arr, 300, data); //fetch the first line of file in order to reach row and columns of 2D Array.
		//printf("row:%d col:%d ", *fetchRowCol(str), *(fetchRowCol(str)+1));
		for (int i = 0; i < 2; i++)
		{
			size[i] = *fetchRowCol(str, i);
			printf("sada:%d", size[i]);
		}
		/*int row = *(fetchRowCol(str));
		printf("row: %d", row);
		int col = *(fetchRowCol(str));
		printf("col: %d", col);*/
		fclose(data);			   
		printf("\n");			   
		system("pause");
	}
}
		/*for (int i = 0; i < satir; i++) {
			printf("%d|", i);
			for (int j = 0; j < sütün+1; j++) {
				dataToBeRead[i][j] = fgetc(data);
				printf("%c", dataToBeRead[i][j]);
			}
		}*/