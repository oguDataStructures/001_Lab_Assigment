#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
void main() {
	FILE* data;
	int err = fopen_s(&data, "blobs1.txt", "r");
	char dataToBeRead[SIZE][SIZE];
	int i = 0;
	int satir = 10;
	int s�t�n = 20;
	char arr[SIZE];
	char* str;
	int a;
	if (data == NULL)
	{
		printf("GfgTest.c file failed to open.");
	}
	else
	{
		str = fgets(arr, 300, data); //ilk sat�r� ald�m

		//ilk sat�r� bo�luktan b�lmek ve sat�r, s�t�na atamak laz�m

		for (int i = 0; i < satir; i++) {
			printf("%d|", i);
			for (int j = 0; j < s�t�n + 1; j++) {
				dataToBeRead[i][j] = fgetc(data);
				printf("%c", dataToBeRead[i][j]);
			}
		}

		printf("\n");

		fclose(data);
		system("pause");
	}
}