#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

int isEmpty();
int isFull();
void push(int item);
int pop();
int peek();
void printStack();

void main(void) {
	int item;
	printf("\n** linear 스택 연산 **\n");
	printStack();
	push(1);    printStack();		// 1 삽입
	printf("\n");
	push(2);    printStack();		// 2 삽입
	printf("\n");
	push(3);	printStack();		// 3 삽입
	printf("\n");

	item = peek(); printStack();	// 현재 top의 원소 출력
	printf("peek => %d", item);
	printf("\n");

	item = pop();  printStack();	// 삭제
	printf("\t pop  => %d", item);
	printf("\n");

	item = pop();  printStack();	// 삭제
	printf("\t pop  => %d", item);
	printf("\n");

	item = pop();  printStack();	// 삭제
	printf("\t pop  => %d", item);

	getchar();
}
int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}
int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}
void push(int item) {
	if (isFull()) {
		printf("stack is full \n");
		return;
	}
	else {
		top++;
		stack[top] = item;
	}
}
int pop() {
	int item;
	if (isEmpty()) {
		printf("stack is empty\n");
		return 0;
	}
	else {
		item = stack[top];
		top--;
		return item;
	}
}
int peek() {
	if (isEmpty()) {
		printf("stack is empty\n");
		return 0;
	}
	else {
		return stack[top];
	}
}
void printStack() {
	int temp = top;
	while (temp != -1) {
		printf("%d", stack[temp]);
		temp--;
	}
}
