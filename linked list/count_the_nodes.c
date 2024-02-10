#include<stdio.h>
// #include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    /* data */
    int data ;
    struct node * link ;
};
struct node* head = NULL;
void traversal(){
    struct node* ptr = head;
    printf("The elements those  are present in the linked list are : \n");
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->link;
    }

}
void insert_begin(int key){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->link = NULL;
    if(head == NULL){
        head = temp;
        return;
    } 
    temp->link = head;
    head = temp;
}
int count(){
    int count = 0;
    struct node* ptr = head;
    while (ptr != NULL)
    {
        /* code */
        count++;
        ptr = ptr->link;
    }
    return count;
    
}

int main(){
    insert_begin(10);
    insert_begin(20);
    insert_begin(30);
    int cnt = count();
    printf("%d",cnt);

return 0;
}