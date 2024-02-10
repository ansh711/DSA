#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define size 10
int queue[size];
int  front = -1,rear=-1;
void enque(int key){
    if(rear == size-1){
        printf("Queue is Full\n");
        return;
    }
    else if(front == -1){
        front = rear = 0;
        queue[rear] = key;
    }
    else{
        rear++;
        queue[rear] = key;
    }
}

int dequeue(){
    if(front == -1){
        printf("Queue is Empty \n");
        return INT_MIN;
    }
    else if(front == rear){
        int temp = queue[front];
        front = rear = -1;
        return temp;

    }
    else{
        int temp = queue[front];
        front++;
        return temp;
    }
}

void display(){
    printf("\nThe queue is = \n");
    for(int i = rear; i>= front ; i--){
        printf("%d\t",queue[i]);
    }
}
int main(){
    do
    {
        /* code */
        int ch;
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n");
        printf("Enter the choice = \n ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            /* code */
            printf("Enter the element you want to insert in the queue = ");
            int item;
            scanf("%d",&item);
            enque(item);
            break;
        case 2:
            int popped = dequeue();
            printf("The element which has been popped from the queue is = %d\n",popped);
            break;
        case 3:
            display();
            break;

        
        default:
            break;
        }
    } while (1);
    

return 0;
}