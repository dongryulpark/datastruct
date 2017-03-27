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
void Input_Matrix(double** Matrix, int Row, int Col);
void Print_Matrix(double** Matrix, int Row, int Col);
void Print_Matrix_File(FILE *Fpointer, double** Matrix, int Row, int Col);
int ModeSelect();
void ModifyMode();
void GetFileList();
void Scanf_File(FILE *Fpointer, double** Matrix, int Row, int Col);
void MakeMode();
char* Make_File_Name();

void Modify_Value(FILE *Fpointer, double** Arry2D);
void Modify_Mode(FILE *Fpointer, double** Arry2D, int Row, int Col);


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
			// todo
			//view
			continue;
		}
		else break;
	}
	
	return 0;
}

void gotoxy(int x, int y){ 
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

double** Make_Matrix(int Row, int Col) {
	int i;
	double **Matrix;

	Matrix = (double**)malloc(sizeof(double*) * Row);
	for (i = 0; i < Row; i++) Matrix[i] = (double*)malloc(sizeof(double) * Col);
	return Matrix;
}

void Delete_Matrix(int Row, double** Matrix) {
	int i;
	for (i = 0; i < Row; i++) free(Matrix[i]);
	free(Matrix);
}

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

void Input_Matrix(double** Matrix, int Row, int Col) {
	int i, j;

	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) {
			gotoxy(MidX - 5, MidY);
			printf("input data");
			gotoxy(MidX - 2, MidY + 1);
			printf("%d X %d", i+1, j+1);
			gotoxy(MidX, MidY + 2);
			scanf_s("%lf", &Matrix[i][j]);
			system("cls");
		}
	}
	getchar(); //clear buffer
}

void Print_Matrix(double** Matrix, int Row, int Col) {
	int i, j;
	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) printf("[ %3.3lf ]", Matrix[i][j]);
		printf("\n");
	}
}

void Print_Matrix_File(FILE *Fpointer, double** Matrix, int Row, int Col){
	int i, j;
	fprintf(Fpointer, "%d %d\n", Row, Col);
	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) fprintf(Fpointer, "%lf ", Matrix[i][j]);
		fprintf(Fpointer, "\n");
	}
}

int ModeSelect() {
	int Mode;

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
		if (Mode == 27) return 4;
		else if (Mode > 51 || Mode <= 48) {
			printf("you must input 1,2,3");
			continue;
		}
		else break;
	}
	return (Mode - 48);
}

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
	printf("input Row and Col");// 규약
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

char* Make_File_Name() {
	char txt[] = ".txt";
	char* FileName, *Path;
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

////////////////////////////////////////////////////////////////////////
void ModifyMode() {
	FILE *Fpointer;
	char * Path;
	int i,j,Row, Col;
	double **Matrix;

	GetFileList();
	gotoxy(MidX - 2, MidY);
	Path = Make_File_Name();
	fopen_s(&Fpointer, Path, "r");
	fscanf_s(Fpointer, "%d %d\n", &Row, &Col);
	
	Matrix = Make_Matrix(Row, Col);
	Scanf_File(Fpointer,  Matrix,Row,Col);
	system("cls");
	gotoxy(MidX - 2,0);
	printf("%s file value:\n",Path);
	Print_Matrix(Matrix, Row, Col);
	







	// todo
	// 어느곳에 있는 벨류 고칠꺼냐 물보고
	// row & col 입력하라하기
	// 수정값받아 다시 쓰기
}

void GetFileList() {
	FILE_SERCH fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\txt\\*.*", &fd); 

	if (handle == -1){
		printf("There were no files.\n");
		system("mkdir txt");
		return;
	}

	while (result != -1){
		printf("File: %s\n", fd.name);
		result = _findnext(handle, &fd);
	}

	_findclose(handle);
}

void Modify_Value(FILE *Fpointer,double** Matrix) {
	int M_Row, M_Col;
	fpos_t filepos = 0;
	printf("modify mode \n");
	printf("input row and col \n");
	scanf_s("%d %d", &M_Row, &M_Col);

	printf("now there is %lf \n", Matrix[M_Row][M_Col]);
	printf("just input value that you want \n");
	scanf_s("%lf", &Matrix[M_Row][M_Col]);
	fsetpos(Fpointer, &filepos);
}

void Modify_Mode( FILE *Fpointer, double** Matrix, int Row, int Col) {
	int i;
	char Modify_Dicide_Value;
	printf("do you want to modify table???? (y / n) \n");
	scanf_s("%c", &Modify_Dicide_Value, sizeof(char));

	if (Modify_Dicide_Value == 'y' || Modify_Dicide_Value == 'Y') {
		Modify_Value(Fpointer, Matrix);
		Print_Matrix_File(Fpointer, Matrix, Row, Col);
		fclose(Fpointer);
	}
	else if (Modify_Dicide_Value == 'n' || Modify_Dicide_Value == 'N') {
		printf("잘가 \n");
		Print_Matrix_File(Fpointer, Matrix, Row, Col);
		for (i = 0; i < Row; i++) free(Matrix[i]);
		free(Matrix);
		fclose(Fpointer);
	}
}