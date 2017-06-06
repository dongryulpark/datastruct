#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode {
	char item;
	struct stackNode* link;
}stackNode;

stackNode* top = NULL;

int isEmpty();
void push(char item);
char pop();
int cheackPare(char* eq);

int main() {
	char eq[] = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", eq);

	if (cheackPare(eq) == 1)
		printf("\n\n수식의 괄호가 맞게 사용되었습니다!");
	else
		printf("\n\n수식의 괄호가 틀렸습니다!");

	getchar();
}

int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}
void push(char item) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->item = item;
	newNode->link = top;
	top = newNode;
}
char pop() {
	stackNode* temp = top;
	char item;

	if (isEmpty()) {
		printf("stack is empty \n");
		return 0;
	}
	else {
		top = temp->link;
		item = temp->item;
		free(temp);
		return item;
	}
}
int cheackPare(char* eq) {
	int length, i = 0;
	char openPair = 0;

	length = strlen(eq);
	for (i = 0; i < length; i++) {
		switch (eq[i]) {
			case '[':
			case '(':
			case '{':
				push(eq[i]); break;
			case ']':
			case ')':
			case '}':
				if (isEmpty()) return 0;
				else {
					openPair = pop();
					if ((openPair == '(' && eq[i] != ')') ||
						(openPair == '[' && eq[i] != ']') ||
						(openPair == '{' && eq[i] != '}'))
						return 0;
					else break;
				}
		}
	}
	if (isEmpty()) return 1;
	else return 0;
}
