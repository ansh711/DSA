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
void last_node(){
    struct node*ptr = head;
    if(head == NULL){
        return;
    }
    else{
        while(ptr->link != NULL){
            ptr = ptr->link ;
        }
        printf("The last element of the linked list is = %d\n",ptr->data);
    }

}

void second_last_node(){
    struct node* ptr = head;
    if(head == NULL || head->link == NULL){
        return;
    }
    else{
        while(ptr->link->link != NULL){
            ptr = ptr->link;
        }
        printf("The second last element of the linked  list is = %d \n" , ptr->data );
    }
}
int main(){
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
    printf("The linked list is = \n");
    traversal();
    printf("\n");
    last_node();
    second_last_node();
    

return 0;
}