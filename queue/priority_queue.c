#include<stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    int priority;
    struct queue* next;
};
struct queue* head = NULL;
struct queue* newnode(int data , int p){
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp ->data = data;
    temp->priority  = p;
    temp->next = NULL;
    return temp; 
}
void enqueue(int data ,int p){
    struct queue* temp = newnode(data, p);
    if(head->priority > p){
        temp->next = head;
        head = temp;
    }
    else{
        while(head->next != NULL && head->next->priority<p){
            head = head->next;
        }
        temp->next = head->next ;
        head->next = temp;
    }
}
void dequeue(){
    if(head == NULL) {printf("Queue is empty\n");return;}
    printf("The element which is removed from the queue is = %d\n ",head->data);
    struct queue *temp = head;
    head = head->next;
    free(temp);


}
int main(){

    

return 0;
}