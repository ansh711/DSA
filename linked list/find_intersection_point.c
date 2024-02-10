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
struct node* head1 = NULL;

void traversal1(){
    struct node* ptr = head;
    // printf("The elements those  are present in the linked list are : \n");
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->link;
    }

}
void traversal2(){
    struct node* ptr = head1;
    // printf("The elements those  are present in the linked list are : \n");
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->link;
    }

}
void insert_begin1(int key){
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
void insert_begin2(int key){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->link = NULL;
    if(head1 == NULL){
        head1 = temp;
        return;
    } 
    temp->link = head1;
    head1 = temp;



}
void create1(){
    int length;
    printf("Enter the length of the linked list to be created = ");
    scanf("%d",&length);
    while(length--)
    {
        /* code */
        int key;
        scanf("%d",&key);
        
        insert_begin1(key);
        


    } 
}
void create2(){
    int length;
    printf("\nEnter the length of the linked list to be created = ");
    scanf("%d",&length);
    while(length--)
    {
        /* code */
        int key;
        scanf("%d",&key);
        
        insert_begin2(key);
        


    } 
}

int intersection_point(){
    int diff = 0;
    int c1=0 , c2 =0;
    struct node * ptr1 = head;
    struct node* ptr2 = head1;
    while(ptr1){
        c1++;
        ptr1 = ptr1 -> link;
    }
    while(ptr2){
        c2++;
        ptr2 = ptr2->link;
    }
    diff = abs(c1 - c2);
    ptr1 = head;
    ptr2 = head1;
    if(c2  > c1 ){
        for (int i = 1; i <= diff; i++)
        {
            /* code */
            ptr2 = ptr2->link;
        }
        
    }
    else if(c1>c2){
        for (int i = 1; i <= diff; i++)
        {
            /* code */
            ptr1 = ptr1->link;
        }
        
    }
    while(ptr1 != ptr2){
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }
    if(ptr1 != NULL){
        return ptr1->data;
    }
    return -1;

}
int main(){

    create1();
    printf("\nThe first linked list is =\n");
    traversal1();
    create2();
    printf("\n\nThe second linked list is =\n");
    traversal2();
    int count = intersection_point();
    if(count == -1){
        printf("\nNo common point found.\n");

    }
    else{
        printf("\nthe node which is the intersection point is = %d\n" , count);
    }




return 0;
}