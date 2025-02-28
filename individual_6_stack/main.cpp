#include <iostream>
#include "Stack.h"
#include "StackList.h"


void getPostfixFromInfix(const char* infix, char* postfix);
bool isOperator(char c);
int getOperatorPrecedence(char op);
bool isValidInfix(const char* infix);


const std::string error_input = "Wrong input string";


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

	try {
		std::cout << "---------------" << '\n';
		char str[15]{};
		getPostfixFromInfix("3+4*2/(1-5)", str);
		std::cout << str << "    end" << '\n';
	}
	catch (std::string error) {
		std::cout << error << '\n';
	}
}


void getPostfixFromInfix(const char* infix, char* postfix) {
	if (!isValidInfix(infix))
		throw error_input;
	StackList<char> stak;
	int p = 0;
	for (int c = 0; c < strlen(infix); c++) {
		if (infix[c] >= '0' && infix[c] <= '9') {
			postfix[p] = infix[c];
			p++;
			continue;
		}
		if (infix[c] == '(') {
			stak.push(infix[c]);
			continue;
		}
		if (infix[c] == ')') {
			while (stak.getfirst() != '(') {
				postfix[p] = stak.pop();
				p++;
			}
			stak.pop();
			continue;
		}
		if (isOperator(infix[c])) {
			while (stak.isEmpty() && getOperatorPrecedence(stak.getfirst()) >= getOperatorPrecedence(infix[c])) {
				postfix[p] = stak.pop();
				p++;
			}
			stak.push(infix[c]);
			continue;
		}
	}
	while (stak.isEmpty()) {
		if (isOperator(stak.getfirst())) {
			postfix[p] = stak.pop();
			p++;
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
	default:
		return 0;
	}
}


bool isValidInfix(const char* infix) {
	StackList<char> stak;
	int c_digit = 0;
	int c_operator = 0;
	for (int i = 0; i < strlen(infix); i++) {
		char current = infix[i];

		if (!isdigit(current) && current != '(' && current != ')' && !isOperator(current))
			return false;

		if (isOperator(current)) {
			c_digit = 0;
			c_operator++;
		}

		if (isdigit(current)) {
			c_digit++;
			if (c_digit == 2)
				return false;
			c_operator = 0;
		}

		if (current == '(') {
			stak.push(current);
			c_digit = 0;
			c_operator = 0;
		}

		else if (current == ')') {
			if (!stak.isEmpty() || stak.getfirst() != '(') {
				return false;
			}
			stak.pop();
			c_digit = 0;
			c_operator = 0;
		}
	}
	return !stak.isEmpty();
}