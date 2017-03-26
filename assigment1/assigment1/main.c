#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MidX 40
#define MidY 17

int ModeSelect();
void MakeMode();
long** Make_2D_Matrix(int Row, int Col);
void Input_Exception_Handling(float *Input_Row, float *Input_Col);
void Input_Matrix(long** Arry2D, int Row, int Col);
void Print_Matrix(long** Arry2D, int Row, int Col);
void Print_Matrix_File(FILE *Fpointer, long** Arry2D,int Row, int Col);
void Modify_Value(FILE *Fpointer, long** Arry2D);
void Modify_Mode(FILE *Fpointer, long** Arry2D, int Row, int Col);
void gotoxy(int x, int y);
void SetConsolPos();

int main(void) {
	
	unsigned int i, Mode,Row, Col, FileNameSize;
	


	
	system("mode con:cols=100 lines=40");
	Mode = ModeSelect();
	
	switch (Mode){
		case 1: // modify
			break;
		case 2: 
			SetConsolPos();
			MakeMode();// make
			break;
		case 3:// view
			break;
		case 4:
			return 0;
			break;
		default: return 0;
	}

	system("cls");
	system("pause");
	return 0;
}

int ModeSelect() {
	int Mode;
	char temp;

	gotoxy(42, 16);
	printf("select mode");
	gotoxy(40, 17);
	printf("1.modify matrix");
	gotoxy(40, 18);
	printf("2.make  matrix");
	gotoxy(40, 19);
	printf("3.view  matrix \n");
	gotoxy(40, 20);


	for (; 1;) {
		Mode = getch();
		if (Mode == 27) return 4;
		else if (Mode > 51 || Mode <= 48) {
			printf("you must input 1,2,3");
			continue;
		}
		else break;
	}
	return (Mode - 48);
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
		Scanf_Return = scanf_s("%f %f", Input_Row, Input_Col);
		while ((temp = getchar()) != EOF && temp != '\n'); // todo이 구문 분석
		if (Scanf_Return == 2) {
			if (*Input_Row <= 0 || *Input_Col <= 0) {
				printf("you must input natural number \n");
				continue;
			}
			else if ((*Input_Row - (int)*Input_Row) != 0 || (*Input_Col - (int)*Input_Col) != 0) {
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

	printf("input value for %d \n", Row * Col);

	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) scanf_s("%d", &Arry2D[i][j]);
	}
	getchar(); // clear buffer
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

void Modify_Mode( FILE *Fpointer, long** Arry2D, int Row, int Col) {
	int i;
	char Modify_Dicide_Value;
	printf("do you want to modify table???? (y / n) \n");
	scanf_s("%c", &Modify_Dicide_Value, sizeof(char));

	if (Modify_Dicide_Value == 'y' || Modify_Dicide_Value == 'Y') {
		Modify_Value(Fpointer, Arry2D);
		Print_Matrix_File(Fpointer, Arry2D, Row, Col);
		fclose(Fpointer);
	}
	else if (Modify_Dicide_Value == 'n' || Modify_Dicide_Value == 'N') {
		printf("잘가 \n");
		Print_Matrix_File(Fpointer, Arry2D, Row, Col);
		for (i = 0; i < Row; i++) free(Arry2D[i]);
		free(Arry2D);
		fclose(Fpointer);
	}
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


char* Make_File_Name() {
	char txt[] = ".txt"; //5
	char* buffer, *FileName, *Path;
	int i, FileNameSize;
	
	printf("input file name \n");
	gotoxy(MidX, MidY+1);
	buffer = (char*)malloc(sizeof(char) * 100);
	scanf_s("%s", buffer, sizeof(char) * 100);
	gotoxy(MidX, MidY + 2);

	for (i = 0; i < 100; i++) {
		if (buffer[i] == '\0') break;
	}
	FileNameSize = i;
	FileName = (char*)malloc(sizeof(char) *(FileNameSize + 6)); //filenamesize + 1

	for (i = 0; i <= FileNameSize; i++) {
		FileName[i] = buffer[i];
	}
	free(buffer);

	Path = (char*)malloc(sizeof(char) * FileNameSize + 20);
	strcpy_s(Path, sizeof(char) * FileNameSize + 20,".\\txt\\");

	strcat_s(FileName, sizeof(char) * (FileNameSize + 6), txt);
	strcat_s(Path, sizeof(char) * (FileNameSize + 20), FileName);
	
	
	free(FileName);
	
	return Path;
}

void MakeMode() {
	//	todo
	//	행렬의 갯수 받기
	//	동적할당
	//	파일저장
	char *dir;
	float Input_Row, Input_Col;
	unsigned int Row, Col;
	long **Arry2D;
	FILE *Fpointer;

	dir = Make_File_Name();
	printf("input Row and Col \n");
	Input_Exception_Handling(&Input_Row, &Input_Col);
	Col = (int)Input_Col; Row = (int)Input_Row;
		
	Arry2D = Make_2D_Matrix(Row, Col);
	Input_Matrix(Arry2D, Row, Col);
	
	Print_Matrix( Arry2D, Row, Col);
	fopen_s(&Fpointer, dir, "w+");
	Print_Matrix_File(Fpointer,Arry2D, Row, Col);
}

void SetConsolPos() {
	system("cls");
	gotoxy(MidX, MidY);
}