#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stack
{
    /* data */
    int data;
    struct stack* link;
};
struct stack* top = NULL;
void push(int key){
    // for stack we have to implement the insertion at begining of linked list for getting O(1) time complexitylike in array
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    temp->data = key;
    temp->link= NULL;
    // struct stack* ptr = top;
    if(top == NULL){
        top = temp;
        return ;


    }
    else{
        temp->link = top;
        top = temp;
    }
}
int pop(){
    struct stack* ptr = top;
    if(top == NULL){
        printf("Stack is Empty \n");
        return INT_MIN;
    }
    else{
        int x = ptr->data;
        top = ptr->link;
        free(ptr);
        return x;

    }
}
int peek(){
    if(top == NULL){
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    else{
        return top->data;
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