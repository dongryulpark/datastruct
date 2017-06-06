#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  stackNode {	// 스택의 노드를 구조체로 정의
	char data;
	struct stackNode *link;
} stackNode;

stackNode* top;				// 스택의 top 노드를 지정하기 위해 포인터 top 선언

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
							// 스택이 공백 상태인지 확인하는 연산
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산


// 스택의 top에서 원소를 삭제하는 연산

void main(void) {
	char* express = "((a*b)-(c/d))";
	printf("중위 표기식 : %s", express);
	express = convertToPostFix(express);
	printf("후위 표기식 : %s \n", express);

	getchar();
}

void push(char item) {
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;		// 삽입 노드를 top의 위에 연결
	top = temp;				// top 위치를 삽입 노드로 이동
}
char pop() {
	char item;
	stackNode* temp = top;

	if (top == NULL) {		// 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// 스택이 공백 리스트가 아닌 경우
		item = temp->data;
		top = temp->link;	// top 위치를 삭제 노드 아래로 이동
		free(temp);			// 삭제된 노드의 메모리 반환
		return item;		// 삭제된 원소 반환
	}
}
