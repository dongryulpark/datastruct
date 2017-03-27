#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MidX 45
#define MidY 17

typedef struct _finddata_t FILE_SERCH;

void gotoxy(int x, int y);

double** Make_Matrix(int Row, int Col);
void Delete_Matrix(int Row, double** Matrix);

void Size_Input_EH(float *Input_Row, float *Input_Col); 
void Pos_Input_EH(float *Input_Row, float *Input_Col, int Row, int Col);
void Value_Input_EH(double** Matrix, int i, int j);

void Input_Matrix(double** Matrix, int Row, int Col);
void Print_Matrix(double** Matrix, int Row, int Col);
void Print_Matrix_File(FILE *Fpointer, double** Matrix, int Row, int Col);
void Scanf_File(FILE *Fpointer, double** Matrix, int Row, int Col);

int ModeSelect();
int ModifyMode();
void GetFileList();
void Modify_Value(FILE *Fpointer, double** Matrix, int Row, int Col);
void MakeMode();
char* Make_File_Name();
int ViewMode();

int main(void) {
	int start, Mode;
	
	system("mode con:cols=100 lines=40");	
	gotoxy(MidX - 13, MidY);
	printf("hello i'm matrix modify program");
	gotoxy(MidX - 14 , MidY + 1);
	printf("if you wnat to start press anykey");
	gotoxy(MidX - 12, MidY + 2);
	printf("if you wnat to exit press ESC");
	gotoxy(MidX, MidY + 3);
	if ((start = getch()) == 27) return 0;
	system("cls");

	
	for (; 1; ) {
		system("cls");
		Mode = ModeSelect();
		if (Mode == 1) {
			system("cls");
			ModifyMode();
			printf("press anykey for continue");
			getch();
			continue;
		}
		else if (Mode == 2) {
			MakeMode();
			printf("press anykey for continue");
			getch();
			continue;
		}
		else if (Mode == 3) {
			ViewMode();
			printf("press anykey for continue");
			getch();
			continue;
		}
		else break;
	}
	
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// gotoxy() : 콘솔의 지정 위치로 이동하는 함수이다.
///////////////////////////////////////////////////////////////////////////////////////////
void gotoxy(int x, int y){ 
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

///////////////////////////////////////////////////////////////////////////////////////////
// Make_Matrix() : 2차원 동적할당 선언함수.
///////////////////////////////////////////////////////////////////////////////////////////
double** Make_Matrix(int Row, int Col) {
	int i;
	double **Matrix;

	Matrix = (double**)malloc(sizeof(double*) * Row);
	for (i = 0; i < Row; i++) Matrix[i] = (double*)malloc(sizeof(double) * Col);
	return Matrix;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Delete_Matrix(): 2차원 동적 할당 free함수.
///////////////////////////////////////////////////////////////////////////////////////////
void Delete_Matrix(int Row, double** Matrix) {
	int i;
	for (i = 0; i < Row; i++) free(Matrix[i]);
	free(Matrix);
}

///////////////////////////////////////////////////////////////////////////////////////////
// Size_Input_EH(): Matrix 함수 사이즈입력시 예외처리 함수.
///////////////////////////////////////////////////////////////////////////////////////////
void Size_Input_EH(float *Input_Row, float *Input_Col) {
	unsigned int Scanf_Return, temp, Pos = 2;
	for (; 1;) {
		gotoxy(MidX, MidY + Pos);
		Scanf_Return = scanf_s("%f %f", Input_Row, Input_Col);
		while ((temp = getchar()) != EOF && temp != '\n');
		if (Scanf_Return == 2) {
			if (*Input_Row <= 0 || *Input_Col <= 0) {
				Pos++;
				gotoxy(MidX - 12, MidY + Pos);
				printf("you must input natural number \n");
				Pos++;
				continue;
			}
			else if ((*Input_Row - (int)*Input_Row) != 0 || (*Input_Col - (int)*Input_Col) != 0) {
				Pos++;
				gotoxy(MidX - 12, MidY  + Pos);
				printf("you must input natural number \n");
				Pos++;
				continue;
			}
			else break;
			
		}
		else {
			Pos++;
			gotoxy(MidX - 12, MidY + Pos);
			printf("you must input natural number \n");
			Pos++;
			continue;
		}
		Pos++;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////
// Pos_Input_EH(): Matrix 수정 위치 입력시 예외처리 함수
///////////////////////////////////////////////////////////////////////////////////////////
void Pos_Input_EH(float *Input_Row, float *Input_Col, int Row, int Col) {
	unsigned int Scanf_Return, temp, Pos = 1;
	
	for (; 1;) {
		gotoxy(MidX, MidY + Pos);
		Scanf_Return = scanf_s("%f %f", Input_Row, Input_Col);
		while ((temp = getchar()) != EOF && temp != '\n');
		if (Scanf_Return == 2) {
			if (*Input_Row <= 0 || *Input_Col <= 0) {
				Pos++;
				gotoxy(MidX - 10, MidY + Pos);
				printf("you must input natural number \n");
				Pos++;
				continue;
			}
			else if ((*Input_Row - (int)*Input_Row) != 0 || (*Input_Col - (int)*Input_Col) != 0) {
				Pos++;
				gotoxy(MidX - 10, MidY + Pos);
				printf("you must input natural number \n");
				Pos++;
				continue;
			}
			else if ( *Input_Row > Row || *Input_Col > Col) {
				Pos++;
				gotoxy(MidX - 10, MidY + Pos);
				printf("you must input range of Matrix \n");
				Pos++;
				continue;
			}
			else { 
				*Input_Col = *Input_Col - 1;
				*Input_Row = *Input_Row - 1;
				break; 
			}
		}
		else {
			Pos++;
			gotoxy(MidX - 12, MidY + Pos);
			printf("you must input natural number \n");
			Pos++;
			continue;
		}
		Pos++;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// Value_Input_EH(): Matrix 값 입력시 예외처리 함수
///////////////////////////////////////////////////////////////////////////////////////////
void Value_Input_EH(double** Matrix, int i, int j) {
	int temp;

	for (; 1;) {
		if (scanf_s("%lf", &Matrix[i][j]) != 1) {
			while ((temp = getchar()) != EOF && temp != '\n');
			gotoxy(MidX - 9, MidY + 2);
			printf("you must input real value");
			gotoxy(MidX, MidY + 3);
			continue;
		}
		else break;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// Value_Input_EH(): Matrix 값 입력시 예외처리 함수
///////////////////////////////////////////////////////////////////////////////////////////
void Input_Matrix(double** Matrix, int Row, int Col) {
	int i, j, pos = 2;

	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) {
			gotoxy(MidX - 5, MidY);
			printf("input data");
			gotoxy(MidX - 2, MidY + 1);
			printf("%d X %d", i+1, j+1);
			gotoxy(MidX, MidY + 2);
			
			Value_Input_EH(Matrix, i,j);

			system("cls");
		}
	}
	getchar(); //clear buffer
}

///////////////////////////////////////////////////////////////////////////////////////////
// Scanf_File(): FILE에 저장된 matrix값 읽어오는 함수
///////////////////////////////////////////////////////////////////////////////////////////
void Scanf_File(FILE *Fpointer, double** Matrix, int Row, int Col) {
	int i, j;
	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) fscanf_s(Fpointer, "%lf ", &Matrix[i][j]);
	}

}

///////////////////////////////////////////////////////////////////////////////////////////
// Print_Matrix(): 콘솔에 Matrix출력하기
///////////////////////////////////////////////////////////////////////////////////////////
void Print_Matrix(double** Matrix, int Row, int Col) {
	int i, j;
	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) printf("[ %3.3lf ]", Matrix[i][j]);
		printf("\n");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// Print_Matrix(): FILE에 Matrix출력하기
///////////////////////////////////////////////////////////////////////////////////////////
void Print_Matrix_File(FILE *Fpointer, double** Matrix, int Row, int Col){
	int i, j;
	fprintf(Fpointer, "%d %d\n", Row, Col);
	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) fprintf(Fpointer, "%lf ", Matrix[i][j]);
		fprintf(Fpointer, "\n");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// ModeSelect(): 동작 모드 선택 함수
///////////////////////////////////////////////////////////////////////////////////////////
int ModeSelect() {
	int Mode, pos = 1;

	gotoxy(MidX - 7, MidY);
	printf("select mode");
	gotoxy(MidX - 8, MidY + 1);
	printf("1.modify matrix");
	gotoxy(MidX - 8, MidY + 2);
	printf("2.make  matrix");
	gotoxy(MidX - 8, MidY + 3);
	printf("3.view  matrix");
	gotoxy(MidX, MidY + 4);
	for (; 1;) {
		Mode = getch();
		gotoxy(MidX - 11, MidY + 4 + pos);
		pos++;
		if (Mode == 27) return 4;
		else if (Mode > 51 || Mode <= 48) {

			printf("you must input 1,2,3");
			continue;
		}
		else break;
	}
	return (Mode - 48);
}

///////////////////////////////////////////////////////////////////////////////////////////
// ModifyMode(): FILE에있는 Matrix값과 동적 할당받은 Matrix 수정함수
///////////////////////////////////////////////////////////////////////////////////////////
int ModifyMode() {
	FILE *Fpointer;
	char * Path;
	int Row, Col;
	double **Matrix;

	GetFileList();
	gotoxy(MidX - 2, MidY);
	Path = Make_File_Name();
	if (fopen_s(&Fpointer, Path, "r") != 0) {
		gotoxy(MidX - 13, MidY + 2);
		printf("there is no file make file");
		gotoxy(MidX - 13, MidY + 3);
		return 0;
	}

	if (fscanf_s(Fpointer, "%d %d", &Row, &Col) != 2) {
		gotoxy(MidX - 13, MidY + 4);
		printf("this File is damaged");
		return 0;
	}

	Matrix = Make_Matrix(Row, Col);
	Scanf_File(Fpointer, Matrix, Row, Col);
	system("cls");
	gotoxy(MidX - 2, 0);
	printf("%s file value:\n", Path);
	Print_Matrix(Matrix, Row, Col);
	fclose(Fpointer);
	fopen_s(&Fpointer, Path, "w+");
	gotoxy(MidX - 2, MidY);
	Modify_Value(Fpointer, Matrix, Row, Col);

	fclose(Fpointer);
	free(Path);
	Delete_Matrix(Row, Matrix);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// GetFileList(): 디렉토리에 있는 파일 이름 출력함수 
///////////////////////////////////////////////////////////////////////////////////////////
void GetFileList() {
	FILE_SERCH fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\txt\\*.*", &fd);

	printf("your working directory files \n");

	if (handle == -1) {
		printf("There were no files.\n");
		system("mkdir txt");
		return;
	}

	while (result != -1) {
		printf("File: %s\n", fd.name);
		result = _findnext(handle, &fd);
	}

	_findclose(handle);
}


///////////////////////////////////////////////////////////////////////////////////////////
// Modify_Value(): 동적 할당받은 Matrix와 FILE에 출력된 Matrix 에 접근하여 값을 바꾸는 함수 
///////////////////////////////////////////////////////////////////////////////////////////
void Modify_Value(FILE *Fpointer, double** Matrix, int Row, int Col) {
	float Input_Row, Input_Col;
	int M_Row, M_Col;
	fpos_t filepos = 0;

	printf("modify mode ");
	gotoxy(MidX - 7, MidY);
	printf("input row and col \n");
	Pos_Input_EH(&Input_Row, &Input_Col, Row, Col);
	M_Row = (int)Input_Row; M_Col = (int)Input_Col;
	gotoxy(MidX - 7, MidY + 2);
	printf("now there is %lf ", Matrix[M_Row][M_Col]);
	gotoxy(MidX - 13, MidY + 3);
	printf("just input value that you want");
	gotoxy(MidX, MidY + 4);
	scanf_s("%lf", &Matrix[M_Row][M_Col]);
	fsetpos(Fpointer, &filepos);
	Print_Matrix_File(Fpointer, Matrix, Row, Col);
	gotoxy(MidX - 8, MidY + 5);
}

///////////////////////////////////////////////////////////////////////////////////////////
// MakeMode(): FILE에저장할 새로운 Matrix를 만드는 함수 
///////////////////////////////////////////////////////////////////////////////////////////
void MakeMode() {
	char *dir;
	int Row, Col;
	float Input_Row, Input_Col;
	double **Matrix;
	FILE *Fpointer;

	system("cls");
	dir = Make_File_Name();
	system("cls");
	gotoxy(MidX - 3, MidY);
	printf("make mode");
	gotoxy(MidX - 7, MidY + 1);

	printf("input Row and Col");
	Size_Input_EH(&Input_Row, &Input_Col);
	Col = (int)Input_Col; Row = (int)Input_Row;

	Matrix = Make_Matrix(Row, Col);
	system("cls");
	Input_Matrix(Matrix, Row, Col);

	Print_Matrix(Matrix, Row, Col);
	fopen_s(&Fpointer, dir, "w+");
	Print_Matrix_File(Fpointer, Matrix, Row, Col);
	fclose(Fpointer);
	Delete_Matrix(Row, Matrix); 
	free(dir);	
}

///////////////////////////////////////////////////////////////////////////////////////////
// Make_File_Name(): FILE의 이름과 경로를 배열로 만드는 함수 
///////////////////////////////////////////////////////////////////////////////////////////
char* Make_File_Name() {
	char* FileName, *Path;
	char txt[] = ".txt";
	int i, FileNameSize;

	FileName = (char*)malloc(sizeof(char) * 100);

	gotoxy(MidX - 7, MidY);
	printf("input file name ");
	gotoxy(MidX, MidY + 1);
	scanf_s("%s", FileName, sizeof(char) * 100);
	
	for (i = 0; i < 100; i++) {
		if (FileName[i] == '\0') break;
	}

	FileNameSize = i + 1;

	Path = (char*)malloc(sizeof(char) * FileNameSize + 14);
	strcpy_s(Path, sizeof(char) * FileNameSize + 14, ".\\txt\\");
	strcat_s(FileName, sizeof(char) * (FileNameSize + 5), txt);
	strcat_s(Path, sizeof(char) * (FileNameSize + 14), FileName);
	free(FileName);

	return Path;
}


///////////////////////////////////////////////////////////////////////////////////////////
// ViewMode(): 시각화 모드 
///////////////////////////////////////////////////////////////////////////////////////////
int ViewMode() {
	FILE *Fpointer;
	char * Path;
	int Row, Col;

	double **Matrix;

	system("cls");

	GetFileList();
	gotoxy(MidX - 2, MidY);
	Path = Make_File_Name();
	if (fopen_s(&Fpointer, Path, "r") != 0) {
		gotoxy(MidX - 13, MidY + 2);
		printf("there is no file in dir");
		gotoxy(MidX - 13, MidY + 3);
		return 1;
	}

	if (fscanf_s(Fpointer, "%d %d", &Row, &Col) != 2) {
		gotoxy(MidX - 13, MidY + 4);
		printf("this File is damaged");
	}
	Matrix = Make_Matrix(Row, Col);
	Scanf_File(Fpointer, Matrix, Row, Col);
	system("cls");
	gotoxy(MidX - 2, 0);
	printf("%s file value:\n", Path);
	Print_Matrix(Matrix, Row, Col);
	fclose(Fpointer);
	free(Path);
	Delete_Matrix(Row, Matrix);
	return 0;
}