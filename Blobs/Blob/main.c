#include <stdio.h>
#include <stdlib.h>

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
	printf("\n   ");
	for (int i = 0; i < col; i++)
	{
		number = i % 10;
		printf("%d", number);
	}
}
void horWall(int col) {
	printf("\n  ");
	printf("+");
	for (int i = 0; i < col; i++)
	{
		printf("-");
	}
	printf("+");
}
void main() {
	FILE* data;
	int err = fopen_s(&data, "blobs1.txt", "r");
	char arr[300];
	char* str;
	int* size[2];
	int row, col;
	int* dataToBeRead;

	if (data == NULL)
	{
		printf("blobs1.c file failed to open.");
		return;
	}
	str = fgets(arr, 300, data); //fetch the first line of file in order to reach row and columns of 2D Array.
	fetchRowCol(str, &size); // throw the string which is include first line with first index of adress of size array 
	row = size[0];
	col = size[1];
	dataToBeRead = (int*)malloc(row * col * sizeof(int));
	horNumbers(col);
	horWall(col);
	printf("\n");

	for (int i = 0; i < row; i++) {
		printf("%d |", i);
		for (int j = 0; j < col + 1; j++) {
			*(dataToBeRead + i * col + j) = fgetc(data);
			printf("%c", *(dataToBeRead + i * col + j));
			if (j == col - 1) {
				printf("| %d", i);
			}
		}
	}
	fclose(data);

	horWall(col);
	horNumbers(col);

	printf("\n");
	system("pause");
}