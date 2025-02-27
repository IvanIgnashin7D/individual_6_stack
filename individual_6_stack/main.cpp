#include <iostream>
#include "Stack.h"
#include "StackList.h"


void getPostfixFromInfix(const char* infix, char* postfix);
bool isOperator(char* c);
int getOperatorPrecedence(char op);


int main() {
	try {
		StackList<char> stak;
		stak.push('a');
		stak.push('b');
		std::cout << stak.isEmpty() << '\n';
		std::cout << stak.pop() << '\n';
		std::cout << stak.pop() << '\n';
		std::cout << stak.pop() << '\n';
		std::cout << stak.isEmpty() << '\n';
	}
	catch (StackUnderflow error) {
		std::cerr << error.what() << '\n';
	}
	char res[10];
	std::cout << res << '\n';
	res += '1';
	std::cout << res << '\n';
}


void getPostfixFromInfix(const char* infix, char* postfix) {
	StackList<char> stak;
	for (int c = 0; c < sizeof(infix); c++) {
		char i = infix[c];
		if (i >= '0' && i <= '9')
			postfix += i;
		if (i == '(')
			stak.push(i);
		if (i == ')') {
			while (stak.getfirst()) { postfix += stak.pop(); }
		//if (isOperator(i))
		}
	}
}


bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}


int getOperatorPrecedence(char op) {
	switch (op) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
}