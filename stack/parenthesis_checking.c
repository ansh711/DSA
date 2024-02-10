#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define size 10
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
int checkpair(char val1 , char val2){
    if((val1=='(' && val2==')') || (val1==  '{' && val2=='}')||(val1=='[' && val2==']')){
        return 1;

    }
    return 0;
}
int checkbalanced(char exp[]){
    int len = strlen(exp);
    for(int i=0 ;i < len ; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);

        }
        else{
            if(top == -1){
                return 0;
            }
            if(checkpair(stack[top] , exp[i])){
                pop();
            }
        }
    }
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char * exp = "((8)(*--$$9)";
    // Check if stack is empty
    if(checkbalanced(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }

return 0;
}