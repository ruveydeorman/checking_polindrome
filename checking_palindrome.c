#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
typedef struct {
	char items[SIZE];
	int top;
}Stack;
void init_stack(Stack* ps) {
	ps->top = -1;
}
int is_empty(Stack* ps) {
	if (ps->top == -1)
		return 1;
	else return 0;
}
int is_full(Stack* ps) {
	if (ps->top == SIZE - 1)
		return 1;
	else return 0;
}
void push(Stack* ps, char item) {
	if (is_full(ps)) {
		printf("stack overflow");
	}
	else {
		ps->top++;
		ps->items[ps->top] = item;
	}

}
char pop(Stack* ps) {
	char item;
	if (is_empty(ps)) {
		printf("stack underflow");
		return '\0';

	}
	else {
		item = ps->items[ps->top];
		ps->top--;
		return item;
	}
}
int check_polindrome(char ch[SIZE]) {
	int i;
	Stack ps;
	init_stack(&ps);
	int len = strlen(ch);
	for (i = 0; i < len; i++) {
		push(&ps, ch[i]);
	}
	for (i = 0; i < len; i++) {
		if (ch[i] != pop(&ps)) {
			return 0;
		}
	}
	return 1;
}


int main() {
	
	char ch[SIZE];
	printf("enter an string:");
	scanf_s("%19s", ch, sizeof(ch));
	if (check_polindrome(ch)) {
		printf("polindrome");
	}
	else {
		printf("is not polindrome");
	}
	return 0;

}