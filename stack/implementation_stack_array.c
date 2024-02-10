#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
int peek(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        return stack[top];
    }
}
int main(){
    do
    {
        /* code */
        int ch;
        printf("1.PUSH\n2.POP\n3.PEEK\n");
        printf("Enter the choice = \n ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            /* code */
            printf("Enter the element you want to insert in the stack = ");
            int item;
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            int popped = pop();
            printf("The element which has been popped from the stack is = %d\n",popped);
            break;
        case 3:
            int peeked = peek();
            printf("The element which is on the top of the stack is = %d\n",peeked);
            break;

        
        default:
            break;
        }
    } while (1);
    

return 0;
}