#include "util.h"

char* getString() {
	int stringLength, j;
	char temp[100];
	char* string;

	fgets(temp, 100, stdin);

	stringLength = strlen(temp);

	string = (char*)malloc(sizeof(char)*(stringLength + 1));

	for (j = 0; j < stringLength - 1; j++)
		string[j] = temp[j];
	string[stringLength - 1] = '\0';
	return string;
}
void escEscape(int offsetY) {
	while (1) {
		printStringAtMiddle("type ESC to escape", offsetY - 18);
		setCursorAtMiddle(offsetY - 17);
		if (_getch() == 27) {
			system("cls");
			break;
		}
	}
}