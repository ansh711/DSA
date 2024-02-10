#include<stdio.h>
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
    // printf("The elements those  are present in the linked list are : \n");
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
void create(){
    int length;
    printf("Enter the length of the linked list to be created = ");
    scanf("%d",&length);
    do
    {
        /* code */
        int key;
        scanf("%d",&key);
        
        insert_begin(key);
        


    } while (length--);
}
void reverse_print(struct node *head){
    if(head){
        reverse_print(head->link);
        printf("%d\t",head->data);
    }
}

struct node* reverse_list(){
    struct node* current = head , *prev = NULL , *next = NULL;
    // if(head != NULL || head->link != NULL){
    //     return ;

    // }
    // else{
        while(current != NULL){
            next = current->link;
            current->link= prev;
            prev = current;
            current = next;
        }
        head = prev;

    // }
}
int main(){

   
        create();
        printf("\nThe created linked list is = \n");
        traversal();
        printf("\nprinting the linked list in reverse manner = \n");
        reverse_print(head);
        printf("\nReverse of Linked List is : \n ");
        reverse_list();
        traversal();



    

return 0;
}