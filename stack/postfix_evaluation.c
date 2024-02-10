#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>
#include<math.h>
#define size 1000
int stack[size];
int top = -1;
int overflow  = 0, underflow = 0;
void push(int key){
    if(top == size-1){
        printf("Stack is full\n");
        return;
    }
    else{
        top++;
        stack[top] = key;
    }
}
int pop(){
    if(top == -1){
        return INT_MIN;
    }
    int x = stack[top];
    top--;
    return x;
}

// check the precedence order of the operators
int prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// check the associativity 
char associativity(char c) {
	if (c == '^')
		return 'R';
	return 'L'; 
}

// The main function to convert infix expression to postfix expression
char result[1000];
int resultIndex = 0;
void infixToPostfix(char s[]) {
	
	int len = strlen(s);
	char Stack[1000];
	int stackIndex = -1;

	for (int i = 0; i < len; i++) {
		char c = s[i];

		// If the scanned character is an operand, add it to the output string.
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			result[resultIndex++] = c;
		}
		// If the scanned character is an ‘(‘, push it to the Stack.
		else if (c == '(') {
			Stack[++stackIndex] = c;
		}
		// If the scanned character is an ‘)’, pop and add to the output string from the Stack
		// until an ‘(‘ is encountered.
		else if (c == ')') {
			while (stackIndex >= 0 && Stack[stackIndex] != '(') {
				result[resultIndex++] = Stack[stackIndex--];
			}
			stackIndex--; // Pop '('
		}
		// If an operator is scanned
		else {
			while (stackIndex >= 0 && (prec(s[i]) < prec(Stack[stackIndex]) ||
									prec(s[i]) == prec(Stack[stackIndex]) &&
										associativity(s[i]) == 'L')) {
				result[resultIndex++] = Stack[stackIndex--];
			}
			Stack[++stackIndex] = c;
		}
	}

	// Pop all the remaining elements from the Stack
	while (stackIndex >= 0) {
		result[resultIndex++] = Stack[stackIndex--];
	}

	result[resultIndex] = '\0';
	printf("%s\n", result);
}
int is_operator(char symbol) {  
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/'|| symbol == '^') {  
        return 1;  
    }  
    return 0;  
}  
int evaluate(char* expression) {  
    int i = 0;  
    char symbol = expression[i];  
    int operand1, operand2, result;  
  
    while (symbol != '\0') {  
        if (symbol >= '0' && symbol <= '9') {  
            int num = symbol - '0';  
            push(num);  
        }  
        else if (is_operator(symbol)) {  
            operand2 = pop();  
            operand1 = pop();  
            switch(symbol) {  
                case '+': 
                    result = operand1 + operand2; 
                    break;  
                case '-': 
                    result = operand1 - operand2; 
                    break;  
                case '*': 
                    result = operand1 * operand2; 
                    break;  
                case '/': 
                    result = operand1 / operand2; 
                    break;  
                case '^':
                    result = pow(operand1,operand2);
                    break;
            }  
            push(result);  
        }  
        i++;  
        symbol = expression[i];  
    }  
    result = pop();  
    return result;  
}  

// Driver code
int main() {
	char exp[] = "2^2^2";

	// Function call
	infixToPostfix(exp);
    int res = evaluate(result);
    printf("%d",res);


	return 0;
}
