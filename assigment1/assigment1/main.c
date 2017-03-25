#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

long** Make_2D_Matrix(int Row, int Col);
void Input_Exception_Handling(float *Input_Row, float *Input_Col);
void Input_Matrix(long** Arry2D, int Row, int Col);
void Print_Matrix(long** Arry2D, int Row, int Col);
void Print_Matrix_File(FILE *Fpointer, long** Arry2D,int Row, int Col);
void Modify_Value(FILE *Fpointer, long** Arry2D);

int main(void) {
	char Modify_Dicide_Value;
	unsigned int i, Row, Col, Scanf_Return = 0;
	float Input_Row, Input_Col;
	long **Arry2D;
	FILE *Fpointer;
	
	system("mode con:cols=50 lines=30");
	// todo
	// 콘솔 크기 생각;

	printf("input Row and Col \n");
	Input_Exception_Handling(&Input_Row, &Input_Col);
	Col = (int)Input_Col; Row = (int)Input_Row;

	Arry2D = Make_2D_Matrix(Row, Col);

	printf("input value for %d \n", Row * Col);
	Input_Matrix(Arry2D, Row, Col);
	
	system("cls");
	
	Print_Matrix(Arry2D, Row, Col);

	fopen_s(&Fpointer,"data.txt", "w+");
	Print_Matrix_File(Fpointer, Arry2D,Row, Col);
	
	printf("do you want to modify table???? (y / n) \n");
	scanf_s("%c", &Modify_Dicide_Value, sizeof(char));

	if (Modify_Dicide_Value == 'y' || Modify_Dicide_Value == 'Y') {
		Modify_Value(Fpointer, Arry2D);
		Print_Matrix_File(Fpointer, Arry2D, Row, Col);
		fclose(Fpointer);
		system("pause");
	}

	else if(Modify_Dicide_Value == 'n' || Modify_Dicide_Value == 'N'){
		for (i = 0; i < Row; i++) free(Arry2D[i]);
		free(Arry2D);
		printf("잘가 \n");
		fclose(Fpointer);
		system("pause");
		return 0;
	}
	return 0;
}

long** Make_2D_Matrix(int Row, int Col) {
	int i;
	long **Arry2D;
	
	Arry2D = (long**)malloc(sizeof(long*) * Row);
	for (i = 0; i < Row; i++) Arry2D[i] = (long*)malloc(sizeof(long) * Col);

	return Arry2D;

}

void Input_Exception_Handling(float *Input_Row, float *Input_Col) {
	unsigned int Scanf_Return, temp;

	for (; 1;) {
		Scanf_Return = scanf_s("%f %f", &Input_Row, &Input_Col);
		while ((temp = getchar()) != EOF && temp != '\n'); // todo이 구문 분석
		if (Scanf_Return == 2) {
			if (Input_Row <= 0 || Input_Col <= 0) {
				printf("you must input natural number \n");
				continue;
			}
			else if ((Input_Row - (int)Input_Row) != 0 || (Input_Col - (int)Input_Col) != 0) {
				printf("you must input natural number \n");
				continue;
			}
			else break;
		}
		else {
			printf("you must input natural number \n");
			continue;
		}
	}
}

void Input_Matrix(long** Arry2D, int Row, int Col) {
	int i, j;

	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) scanf_s("%d", &Arry2D[i][j]);
	}
	getchar();
	// todo 
	// 하나의 값씩 입력하는데 한줄입력하고 띄우고 싶음 공부를 함
	// consol goto 구문 사용

}


void Print_Matrix(long** Arry2D, int Row, int Col) {
	int i, j;

	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) printf("[ %3.3d ]", Arry2D[i][j]);
		printf("\n");
	}
}


void Print_Matrix_File(FILE *Fpointer, long** Arry2D, int Row, int Col){
	int i, j;
	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) fprintf(Fpointer, "%d ", Arry2D[i][j]);
		fprintf(Fpointer, "\n");
	}
}


void Modify_Value(FILE *Fpointer,long** Arry2D) {
	int M_Row, M_Col;
	fpos_t filepos = 0;
	printf("modify mode \n");
	printf("input row and col \n");
	scanf_s("%d %d", &M_Row, &M_Col);
	printf("now there is %d \n", Arry2D[M_Row][M_Col]);
	
	printf("just input value that you want \n");
	scanf_s("%d", &Arry2D[M_Row][M_Col]);
	fsetpos(Fpointer, &filepos);
}