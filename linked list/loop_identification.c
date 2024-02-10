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
    while(length--)
    {
        /* code */
        int key;
        scanf("%d",&key);
        
        insert_begin(key);
        


    } 
}

int detect_loop(){
    struct node* slow = head , *fast = head;
    if(head == NULL){
        return 0;
    }
    else{
        while(fast != NULL && fast->link != NULL){
            slow = slow->link;
            fast = fast ->link -> link;
            if(slow == fast){
                return 1;
            }

        }
        return 0;

    }
}
int main(){
    create();
    printf("\n The linked list created is = \n");
    traversal();
    int loop = detect_loop();
    if(loop == 1){
        printf("\nThere is a loop in the linked list\n");
    }
    else{
        printf("\nNo loop\n");
    }


return 0;
}