#include <stdio.h>
#include <stdlib.h>
#define SIZE 300
int rowColPixel[3];
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
typedef struct {
	float x;
	float y;
}newCoord;
newCoord newCoord1;

int BlobCount(int N, int M, int r, int c, int* dataToBeRead)
{
	int pixelNum = 0;

	if (r < 0 || r >= N || c < 0 || c >= M)
		return 0;
	if (*(dataToBeRead + r * M + c) == ' ')
		return 0;
	if (*(dataToBeRead + r * M + c) == NULL) {
		return 0;
	}
	else
	{
		newCoord1.x = newCoord1.x + r;
		newCoord1.y = newCoord1.y + c;
		*(dataToBeRead + r * M + c) = ' ';
		pixelNum = (1 + BlobCount(N, M, r, c - 1, dataToBeRead) + BlobCount(N, M, r, c + 1, dataToBeRead) +
			BlobCount(N, M, r - 1, c, dataToBeRead) + BlobCount(N, M, r + 1, c, dataToBeRead));
		return pixelNum;
	}
}
double COMX(int newRow, int newCol, int* tempArrayofData, int pixelNum)
{
	int coord_Sum_X = 0;
	double COMx = 0;
	for (int i = 0; i <= newRow; i++)
	{
		for (int j = 0; j <= newCol; j++)
		{
			coord_Sum_X += i;
		}
	}
	COMx = coord_Sum_X / (double)pixelNum;
	return COMx;
}
double COMY(int newRow, int newCol, int* tempArrayofData, int pixelNum)
{
	int coord_Sum_Y = 0;
	double COMy = 0;
	for (int i = 0; i <= newRow; i++)
	{
		for (int j = 0; j <= newCol; j++)
		{
			coord_Sum_Y += j;
		}
	}
	COMy = coord_Sum_Y / (double)pixelNum;
	return COMy;
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
		str = fgets(arr, 300, data); //fetch the first line of file in order to reach row and columns of 2D Array which is the file.
		fetchRowCol(str, &size); // throw the string which is include first line with first index of adress of size array 
		int row = size[0];// assign the value of row to variable
		int col = size[1];//assign the value of column to variable 
		int* dataToBeRead = (int*)malloc(row * col * sizeof(int));
		int* tempArrayOfData = (int*)malloc(row * col * sizeof(int));
		horNumbers(col);//Making horizontal Counter  to top of table
		horWall(col);//Making horizontal Border to to top of table
		for (int i = 0; i < row; i++) {
			printf("%d|", i);//Making vertical border to left side of table
			for (int j = 0; j < col + 1; j++) {
				*(dataToBeRead + i * col + j) = fgetc(data);//get the character 1 by 1 and set to into 2D dynamic allacoted array
				*(tempArrayOfData + i * col + j) = *(dataToBeRead + i * col + j);
				printf("%c", *(dataToBeRead + i * col + j));//print to log 1 by 1 character from 2D dynamic allacoted array 
				if (j == col - 1) {
					printf("| %d", i);//Making vertical border to right side of table
				}//end-if
			}//end-for-inner
		}//end-for-outer 
		horWall(col);////Making horizontal Counter  to top of table
		horNumbers(col);//Making horizontal Border to bottom of table
		printf("\n");
		int* ptr;
		float newCol, newRow;
		float COMx, COMy;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				newCoord1.x = 0;
				newCoord1.y = 0;
				numberPixel = BlobCount(row, col, i, j, dataToBeRead);

				if (numberPixel > 0)
				{
					
					/*newRow = newCoord1.x;
					newCol = newCoord1.y;
					COMx = COMX(newRow, newCol, tempArrayOfData, numberPixel);
					COMy = COMY(newRow, newCol, tempArrayOfData, numberPixel);*/

					newRow = ( newCoord1.x / (float)numberPixel);
					newCol = ( newCoord1.y / (float)numberPixel);

					blobCounter[numberBloob] = numberPixel;
					printf("\nBlob %d: %d\t", numberBloob + 1, numberPixel);
					printf("x: %.2f\t", newRow);
					printf("y: %.2f", newCol);
					numberBloob++;
				}
			}
		}
	}
	fclose(data);
	printf("\n");
	system("pause");

}