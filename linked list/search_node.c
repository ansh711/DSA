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
// void create(){
//     int length;
//     printf("Enter the length of the linked list to be created = ");
//     scanf("%d",&length);
//     do
//     {
//         /* code */
//         int key;
//         scanf("%d",&key);
        
//         insert_begin(key);
        


//     } while (length--);
// }

void search_any_node(int item){
    struct node* ptr = head;
    int position = 1;
    while(ptr!= NULL){
        if(ptr->data == item){
            printf("\n Element is found at position %d ",position);
            return;
        }
        position++;
        ptr = ptr->link;
    }
    printf("\nThe element is not found in the linked list \n");
}

void search_middle_element(){
    struct node *slow_ptr=head, *fast_ptr=head;
    if(head == NULL){
        printf("List is empty \n");
    }
    else{
        while(fast_ptr != NULL && fast_ptr->link != NULL){
            slow_ptr = slow_ptr->link;
            fast_ptr = fast_ptr->link->link;
        }
        printf("The middle element of the linked list is %d\n", slow_ptr->data);
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
    int element_search ;
    printf("Enter the element to be searched in the linked list = ");
    scanf("%d",&element_search);
    search_any_node(element_search);
    printf("\n");
    // printf("The middle element of the linked list is =  ");
    search_middle_element();

return 0;
}