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
char* Make_File(int *selection);
int ViewMode();

int main(void) {
	int start, Mode;
	
	system("mode con:cols=100 lines=40");	
	gotoxy(MidX - 13, MidY);
	printf("hello i'm matrix modify program");
	gotoxy(MidX - 14 , MidY + 1);
	printf("if you want to start press anykey");
	gotoxy(MidX - 14, MidY + 2);
	printf("copyright donryul Park yejin Lee");
	gotoxy(MidX - 12, MidY + 3);
	printf("if you want to exit press ESC");
	gotoxy(MidX, MidY + 4);
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
// gotoxy() : �ܼ��� ���� ��ġ�� �̵��ϴ� �Լ��̴�.
///////////////////////////////////////////////////////////////////////////////////////////
void gotoxy(int x, int y){ 
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

///////////////////////////////////////////////////////////////////////////////////////////
// Make_Matrix() : 2���� �����Ҵ� �����Լ�.
///////////////////////////////////////////////////////////////////////////////////////////
double** Make_Matrix(int Row, int Col) {
	int i;
	double **Matrix;

	Matrix = (double**)malloc(sizeof(double*) * Row);
	for (i = 0; i < Row; i++) Matrix[i] = (double*)malloc(sizeof(double) * Col);

	return Matrix;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Delete_Matrix(): 2���� ���� �Ҵ� free�Լ�.
///////////////////////////////////////////////////////////////////////////////////////////
void Delete_Matrix(int Row, double** Matrix) {
	int i;
	for (i = 0; i < Row; i++) free(Matrix[i]);
	free(Matrix);
}

///////////////////////////////////////////////////////////////////////////////////////////
// Size_Input_EH(): Matrix �Լ� �������Է½� ����ó�� �Լ�.
///////////////////////////////////////////////////////////////////////////////////////////
void Size_Input_EH(float *Input_Row, float *Input_Col) {
	unsigned int Scanf_Return, temp;
	for (; 1;) {
		gotoxy(MidX, MidY + 3);
		Scanf_Return = scanf_s("%f %f", Input_Row, Input_Col);
		while ((temp = getchar()) != EOF && temp != '\n');
		if (Scanf_Return == 2) {
			if (*Input_Row <= 0 || *Input_Col <= 0) {
				gotoxy(MidX - 12, MidY + 2);
				printf("you must input natural number");
				gotoxy(MidX , MidY + 3);
				printf("                             ");
				continue;
			}
			else if ((*Input_Row - (int)*Input_Row) != 0 || (*Input_Col - (int)*Input_Col) != 0) {
				gotoxy(MidX - 12, MidY  + 2);
				printf("you must input natural number");
				gotoxy(MidX, MidY + 3);
				printf("                             ");
				continue;
			}
			else break;
			
		}
		else {
			gotoxy(MidX - 12, MidY + 2);
			printf("you must input natural number");
			gotoxy(MidX, MidY + 3);
			printf("                             ");
			continue;
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////
// Pos_Input_EH(): Matrix ���� ��ġ �Է½� ����ó�� �Լ�
///////////////////////////////////////////////////////////////////////////////////////////
void Pos_Input_EH(float *Input_Row, float *Input_Col, int Row, int Col) {
	unsigned int Scanf_Return, temp;
	
	for (; 1;) {
		gotoxy(MidX, MidY + 2);
		Scanf_Return = scanf_s("%f %f", Input_Row, Input_Col);
		while ((temp = getchar()) != EOF && temp != '\n');
		if (Scanf_Return == 2) {
			if (*Input_Row <= 0 || *Input_Col <= 0) {
				gotoxy(MidX - 12, MidY + 1);
				printf("you must input natural number");
				gotoxy(MidX, MidY + 2);
				printf("                             ");
				continue;
			}
			else if ((*Input_Row - (int)*Input_Row) != 0 || (*Input_Col - (int)*Input_Col) != 0) {
				gotoxy(MidX - 12, MidY + 1);
				printf("you must input natural number");
				gotoxy(MidX, MidY + 2);
				printf("                             ");
				continue;
			}
			else if ( *Input_Row > Row || *Input_Col > Col) {
				gotoxy(MidX - 12, MidY + 1);
				printf("you must input natural number");
				gotoxy(MidX, MidY + 2);
				printf("                             ");
				continue;
			}
			else { 
				*Input_Col = *Input_Col - 1;
				*Input_Row = *Input_Row - 1;
				break; 
			}
		}
		else {
			gotoxy(MidX - 12, MidY + 1);
			printf("you must input natural number");
			gotoxy(MidX, MidY + 2);
			printf("                             ");
			continue;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// Value_Input_EH(): Matrix �� �Է½� ����ó�� �Լ�
///////////////////////////////////////////////////////////////////////////////////////////
void Value_Input_EH(double** Matrix, int i, int j) {
	int temp;

	for (; 1;) {
		if (scanf_s("%lf", &Matrix[i][j]) != 1) {
			while ((temp = getchar()) != EOF && temp != '\n');
			gotoxy(MidX - 12, MidY + 2);
			printf("you must input real value");
			gotoxy(MidX, MidY + 3);
			printf("                         ");
			gotoxy(MidX, MidY + 3);
			continue;
		}
		else break;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// Input_Matrix(): Matrix �� �Է��Լ�
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
// Scanf_File(): FILE�� ����� matrix�� �о���� �Լ�
///////////////////////////////////////////////////////////////////////////////////////////
void Scanf_File(FILE *Fpointer, double** Matrix, int Row, int Col) {
	int i, j;
	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) fscanf_s(Fpointer, "%lf ", &Matrix[i][j]);
	}

}

///////////////////////////////////////////////////////////////////////////////////////////
// Print_Matrix(): �ֿܼ� Matrix����ϱ�
///////////////////////////////////////////////////////////////////////////////////////////
void Print_Matrix(double** Matrix, int Row, int Col) {
	int i, j;
	for (i = 0; i < Row; i++) {
		for (j = 0; j < Col; j++) printf("[ %3.3lf ]", Matrix[i][j]);
		printf("\n");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// Print_Matrix_File(): FILE�� Matrix����ϱ�
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
// ModeSelect(): ���� ��� ���� �Լ�
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
		gotoxy(MidX - 11, MidY + 4 );
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
// ModifyMode(): FILE���ִ� Matrix���� ���� �Ҵ���� Matrix �����Լ�
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
		gotoxy(MidX - 5, MidY + 2);
		printf("this File is damaged");
		gotoxy(MidX - 8, MidY + 3);
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
// GetFileList(): ���丮�� �ִ� ���� �̸� ����Լ� 
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
// Modify_Value(): ���� �Ҵ���� Matrix�� FILE�� ��µ� Matrix �� �����Ͽ� ���� �ٲٴ� �Լ� 
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
// MakeMode(): FILE�������� ���ο� Matrix�� ����� �Լ� 
///////////////////////////////////////////////////////////////////////////////////////////
void MakeMode() {
	char *dir;
	int Row, Col, formselect;
	float Input_Row, Input_Col;
	double **Matrix;
	FILE *Fpointer = 0;

	system("cls");
	dir = Make_File(&formselect);
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

	if (formselect == 1) {
		fopen_s(&Fpointer, dir, "w+");
	}
	else if (formselect == 2) {
		fopen_s(&Fpointer, dir, "wb+");
	}

	Print_Matrix_File(Fpointer, Matrix, Row, Col);
	fclose(Fpointer);
	Delete_Matrix(Row, Matrix); 
	free(dir);	
}

///////////////////////////////////////////////////////////////////////////////////////////
// Make_File_Name(): FILE�� �̸��� ��θ� �迭�� ����� �Լ� 
///////////////////////////////////////////////////////////////////////////////////////////
char* Make_File_Name() {
	char* FileName, *Path;
	int i, FileNameSize;

	FileName = (char*)malloc(sizeof(char) * 100);

	gotoxy(MidX - 12, MidY);
	printf("input file name and extension");
	gotoxy(MidX, MidY + 1);
	scanf_s("%s", FileName, sizeof(char) * 100);
	
	for (i = 0; i < 100; i++) {
		if (FileName[i] == '\0') break;
	}

	FileNameSize = i + 1;

	Path = (char*)malloc(sizeof(char) * FileNameSize + 14);
	strcpy_s(Path, sizeof(char) * FileNameSize + 14, ".\\txt\\");
	strcat_s(Path, sizeof(char) * (FileNameSize + 14), FileName);
	free(FileName);

	return Path;
}
///////////////////////////////////////////////////////////////////////////////
// Make_File(): bin������ ���ϸ�� txt������ ���ϸ��� ����� �Լ� 
/////////////////////////////////////////////////////////////////////////////
char* Make_File(int *formselect) {
	char* FileName, *Path;
	char txt[] = ".txt", bin[] = ".bin";
	int i, FileNameSize;

	FileName = (char*)malloc(sizeof(char) * 100);

	gotoxy(MidX - 7, MidY);
	printf("select file save form");
	gotoxy(MidX - 7, MidY + 1);
	printf("1. txt file");
	gotoxy(MidX - 7, MidY + 2);
	printf("2. bin file");
	gotoxy(MidX - 7, MidY + 3);
	scanf_s("%d", formselect);
	gotoxy(MidX - 7, MidY + 4);
	printf("input file name ");
	gotoxy(MidX, MidY + 5);
	scanf_s("%s", FileName, sizeof(char) * 100);

	for (i = 0; i < 100; i++) {
		if (FileName[i] == '\0') break;
	}

	FileNameSize = i + 1;

	Path = (char*)malloc(sizeof(char) * FileNameSize + 14);
	strcpy_s(Path, sizeof(char) * FileNameSize + 14, ".\\txt\\");
	if (*formselect == 1) {
		strcat_s(FileName, sizeof(char) * (FileNameSize + 5), txt);
		strcat_s(Path, sizeof(char) * (FileNameSize + 14), FileName);
	}
	else if (*formselect == 2) {
		strcat_s(FileName, sizeof(char) * (FileNameSize + 5), bin);
		strcat_s(Path, sizeof(char) * (FileNameSize + 14), FileName);
	}
	free(FileName);
	return Path;
}

///////////////////////////////////////////////////////////////////////////////////////////
// ViewMode(): �ð�ȭ ��� 
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
		gotoxy(MidX - 5, MidY + 2);
		printf("this File is damaged");
		gotoxy(MidX - 7, MidY + 3);
		return 0;
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