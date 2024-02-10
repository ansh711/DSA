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
void insert_end(int key){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->link=NULL;
    struct node *ptr = head;
    if(head == NULL){
        insert_begin(key) ;
    }
    while(ptr->link!=NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void insert_specific(int position , int key){
    struct node* temp = (struct node *) malloc(sizeof(struct node)) ;
    temp -> data = key;
    temp->link =  NULL;
    if(position==1){
        insert_begin(key);

    }
    else{
        struct node *ptr = head;
        for(int i = 0 ; i<position-2; i++){
            ptr = ptr->link ;

        }
        temp->link = ptr->link;
        ptr->link = temp;



    }
        
    
}
int main(){
    
    do{
        printf("\n1.INSERT AT BEGIN\n2.INSERT AT END\n3.INSERT AT SPECIFIC POSITION\n4.TRAVERSAL\n");
        int choice;
        printf("Enter your choice = \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            /* code */
            int ele;
            printf("Enter the element to be inserted : ");
            scanf("%d" , &ele);
            insert_begin(ele);
            break;
        case 2:
            int element;
            printf("Element to be inserted: ");
            scanf("%d" , &element);
            insert_end(element);
            break;
        case 3:
            printf("Enter the element to be inserted :");
            int pos , key;
            scanf("%d",&key);
            printf("Enter the position where you want to insert this element : ");
            scanf("%d" , &pos);
            insert_specific(pos, key);
            break;
        case 4:
            printf("The final linked list is = \n");
            traversal();
            break;


        
        default:
            break;
        }

    }while(1);

return 0;
}