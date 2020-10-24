
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
//
//int strcmp(const char* str1, const char* str2) {
//	for (int i = 0; i < sizeof(*str1); i++)
//	{
//
//	}
//}
int BlobCount(int row, int col, int r, int c, int* dataToBeRead, float* COMx, float* COMy)
{

	//start-statements
	if (r < 0 || r >= row || c < 0 || c >= col)
		return 0;
	if (*(dataToBeRead + r * col + c) == ' ')
		return 0;
	if (*(dataToBeRead + r * col + c) == NULL) {
		return 0;
	}//end-statements
	else
	{
		*COMx =  *COMx + r;//Get current pixel of X coordinate and Add previous pixel's X coordinate by using newCoord Sturct
		*COMy = *COMy + c;////Get current pixel of X coordinate and Add previous pixel's X coordinate by using newCoord Sturct
		*(dataToBeRead + r * col + c) = ' ';
		return (1 + BlobCount(row, col, r, c - 1, dataToBeRead, COMx, COMy) + BlobCount(row, col, r, c + 1, dataToBeRead, COMx, COMy) +
			BlobCount(row, col, r - 1, c, dataToBeRead, COMx, COMy) + BlobCount(row, col, r + 1, c, dataToBeRead, COMx, COMy));
	}
}

// Function that compares the two string 
//int compareStrings(char* x, char* y)
//{
//	int flag = 0;
//
//	// Iterate a loop till the end 
//	// of both the strings 
//	while (*x != '\0' || *y != '\0') {
//		if (*x == *y) {
//			x++;
//			y++;
//		}
//
//		// If two characters are not same 
//		// set to flag = 1
//		else if ((*x == '\0' && *y != '\0') || (*x != '\0' && *y == '\0') || *x != *y) {
//			flag = 1;
//		}
//	}
//
//	// If two strings are exactly same 
// 
//	if (flag == 1) {
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}


void main() {
	
	FILE* data;
	int err = fopen_s(&data, "blobs1.txt", "r");
	char arr[SIZE];
	char* str;
	int* size[2];
	int numberPixel;
	int numberBloob = 0;
	int blobCounter[SIZE];//dinamik yapılcak!!!
	if (data == NULL)
	{
		printf("Test.c file failed to open.");
	}
	else
	{
		str = fgets(arr, 300, data); //fetch the first line of file in order to access row and columns of 2D Array which is the file.
		fetchRowCol(str, &size); // throw the string which is include first line with first index of adress of size array 
		int row = size[0];// assign the value of row to variable
		int col = size[1];//assign the value of column to variable 
		if (row <= 0 || col <= 0) {
			printf("WARNING! The provided sizes does not generate 2D Array! Please assign valid value to row and colmun! \n");
		}
		else
		{
			int* dataToBeRead = (int*)malloc(row * col * sizeof(int));//Generate dynamic memory for 2D array which we dont know size of it at beggining.
			horNumbers(col);//Making horizontal Counter  to top of table
			horWall(col);//Making horizontal Border to to top of table
			for (int i = 0; i < row; i++) {
				if (i >= 10) {
					printf("%d|", i % 10);
				}
				else
				{
					printf("%d|", i);//Making vertical border to left side of table
				}
				for (int j = 0; j < col + 1; j++) {
					*(dataToBeRead + i * col + j) = fgetc(data);//get the character 1 by 1 and set to into 2D dynamic allacoted array
					printf("%c", *(dataToBeRead + i * col + j));//print to log 1 by 1 character from 2D dynamic allacoted array 
					if (j == col - 1) {
						printf("|%d", i);//Making vertical border to right side of table
					}//end-if
				}//end-for-inner
			}//end-for-outer 
			horWall(col);////Making horizontal Counter  to top of table
			horNumbers(col);//Making horizontal Border to bottom of table
			printf("\n");
			float massOfX, massOfY;
			float *COMx, *COMy;
			COMx = &massOfX;
			COMy = &massOfY;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					*COMx = 0;//Set to 0 newCoord1.x for each bloob's sum X coordinates of their pixels at initial
					*COMy= 0;//Set to 0 newCoord1.y for each bloob's sum Y coordinates of their pixels at initial
					numberPixel = BlobCount(row, col, i, j, dataToBeRead, COMx, COMy);// return number of pixels for each bloob.Additevly, struct sum of X coordinates for each bloob's pixels and
																		  //sum of Y coordinates for each bloob's pixels

					if (numberPixel > 1)
					{

						blobCounter[numberBloob] = numberPixel;
						massOfX = massOfX / (float)(numberPixel);
						massOfY = massOfY / (float)(numberPixel);
						//Print Process
						printf("\nBlob %d: %d\t", numberBloob + 1, numberPixel);
						printf("x: %.2f\t", massOfX);
						printf("y: %.2f", massOfY);
						//End-Print-Process
						numberBloob++;

					}
				}
			}
			if (numberBloob == 0) printf("\nThe 2D Array does not have any bloob!\n");
		}

	}
	fclose(data);
	printf("\n");
	system("pause");

}