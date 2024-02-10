#include<stdio.h>
#include<stdlib.h>
struct queue
{
    /* data */
    int data ;
    struct queue* next ;
};
struct queue* front = NULL;
struct queue* rear = NULL;

struct queue* head = NULL;


void enqueue(int key){
   // for linked list implementation we have to insert in the end of the queue
   // because the queue is following FIFO method 
   // that's how rear will be updated
    struct queue* temp = (struct queue* )malloc(sizeof(struct queue));
    temp->data = key;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front = temp;
        rear = temp;
        head = temp;
        return;
    }
    else{
        struct queue* ptr = head;
        while(ptr->next!= NULL){
            ptr= ptr->next;
        }
        ptr->next = temp;
        rear = temp;
    }

}
void dequeue(){
    // delete from the beginning for that  front will be updated 
    if(head == NULL){
        printf("The queue is empty\n");
        return;
    }
    else{
        struct queue* temp = head;
        head= temp->next;
        front = head;
        printf("the element that is deleted from the queue is = %d\n",temp->data);

    }
}

void display(){
    struct queue* temp = head;
    while(temp!= NULL){
        printf("%d\t",temp->data);
        temp= temp->next;
    }
    printf("\n");
}


int main(){
    int j=1;
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
            enqueue(item);
            break;
        case 2:
            dequeue();
            
            break;
        case 3:
            display();
            break;

        
        default:
            break;
            j=0;
        }
    } while (j==1);
    
return 0;
}