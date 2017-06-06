#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;

stackNode* top = NULL;

void push(int data);
int pop();
int calBack(char* express);
int isOperator(char operator);
int calArithmeticOperation(int order, int num1, int num2);

int main() {
	char* express = "35*62/-";
	calBack(express);

	system("pause");
}

void push(int data) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));

	newNode->data = data;
	newNode->link = top;
	top = newNode;
}
int pop() {
	stackNode* temp = top;
	int data;
	if (top == NULL) {
		printf("stack is empty");
		return 0;
	}
	else {
		data = temp->data;
		top = temp->link;
		free(temp);
		return data;
	}
}
int calBack(char* express) {
	int length, i = 0, tempResult;
	length = strlen(express);

	for (i = 0; i <= length; i++){
		if (isOperator(express[i])) {
			tempResult = calArithmeticOperation(isOperator(express[i]), pop(), pop());
			push(tempResult);
		}
		else if (express[i] == NULL) {
			printf("result is %d", pop());
		}
		else {
			push(express[i]);
		}
	}
}
int isOperator(char operator) {
	if (operator == '+')
		return 1;
	else if (operator == '-')
		return 2;
	else if (operator == '/')
		return 3;
	else if (operator == '*')
		return 4;
	else
		return 0;
}
int calArithmeticOperation(int order, int num1, int num2) {
	int result = 0;
	switch (order){
		case 1: result = (num1 - 48) + (num2 - 48);
			break;
		case 2: result = (num1 - 48) - (num2 - 48);
			break;
		case 3: result = (num1 - 48) / (num2 - 48);
			break;
		case 4: result = (num1 - 48) * (num2 - 48);
			break;
		default:
			break;
	}
	return result;
}