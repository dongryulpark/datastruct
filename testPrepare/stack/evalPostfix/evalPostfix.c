#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  stackNode {	// ������ ��带 ����ü�� ����
	char data;
	struct stackNode *link;
} stackNode;

stackNode* top;				// ������ top ��带 �����ϱ� ���� ������ top ����

void push(char item);
char pop();
int isOpareator(char oparator) {
	if (oparator == '+')
		return 1;
	else if (oparator == '-')
		return 1;
	else if (oparator == '/')
		return 1;
	else if (oparator == '*')
		return 1;
	else
		return 0;
}

char* convertToPostFix(char* express) {
	int length, i = 0, index = 0;
	char *convertedString;
	stackNode* temp;

	length = strlen(express);
	convertedString = (char*)malloc(sizeof(char)*(length+1));

	for (i = 0; i < length; i++){
		if (isOpareator(express[i]))
			push(express[i]);
		else if (express[i] == ')') {
			convertedString[index++] = express[i];
			convertedString[index++] = pop();
		}
		else if (express[i] == NULL) {
			temp = top;
			while (temp != NULL) {
				convertedString[index++] = pop();
				temp = temp->link;
			}
		}
		else 
			convertedString[index++] = express[i];
	}
	convertedString[length] = '\0';
	return convertedString;
}
							// ������ ���� �������� Ȯ���ϴ� ����
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����


// ������ top���� ���Ҹ� �����ϴ� ����

void main(void) {
	char* express = "((a*b)-(c/d))";
	printf("���� ǥ��� : %s", express);
	express = convertToPostFix(express);
	printf("���� ǥ��� : %s \n", express);

	getchar();
}

void push(char item) {
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;		// ���� ��带 top�� ���� ����
	top = temp;				// top ��ġ�� ���� ���� �̵�
}
char pop() {
	char item;
	stackNode* temp = top;

	if (top == NULL) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;	// top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);			// ������ ����� �޸� ��ȯ
		return item;		// ������ ���� ��ȯ
	}
}
