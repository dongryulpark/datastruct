#include "printmode.h"

void printMode() {
	struct DoublyLinkedNode* temp = head;
	int offsetY = 0;

	printf("Forward: \n");
	while (temp != NULL) {
		//studantID, name,sex,contact, address
		printf("%s ", temp->studantID);
		printf("%s ", temp->name);
		printf("%s ", temp->sex);
		printf("%s ", temp->contact);
		printf("%s ", temp->address);
		printf("\n");
		temp = temp->next;
		offsetY++;
	}
	while (1) {
		printStringAtMiddle("type ESC to escape", offsetY - 18);
		setCursorAtMiddle(offsetY - 17);
		if (_getch() == 27) {
			system("cls");
			break;
		}
	}
}