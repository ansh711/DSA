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
// void insert_end(int key){
//     struct node* temp = (struct node*)malloc(sizeof(struct node));
//     temp->data=key;
//     temp->link=NULL;
//     struct node *ptr = head;
//     if(head == NULL){
//         insert_begin(key) ;
//     }
//     while(ptr->link!=NULL){
//         ptr = ptr->link;
//     }
//     ptr->link = temp;
// }

// void insert_specific(int position , int key){
//     struct node* temp = (struct node *) malloc(sizeof(struct node)) ;
//     temp -> data = key;
//     temp->link =  NULL;
//     if(position==1){
//         insert_begin(key);

//     }
//     else{
//         struct node *ptr = head;
//         for(int i = 0 ; i<position-2; i++){
//             ptr = ptr->link ;

//         }
//         temp->link = ptr->link;
//         ptr->link = temp;



//     }
        
    
// }
void delete_begin(){
    if(head==NULL){
        printf("The list is already empty\n");
    }
    else{
        struct node *temp = head;
        head = temp->link;
        free(temp);
    }
}

void delete_end(){
    struct node *temp = head;
    struct node* next = head->link;// struct node* prev = NULL;
    if(head == NULL){
        printf("The list is already empty \n") ;
    
    }
    else if(head->link == NULL){
        head = NULL;
        free(temp);
    }
    else{
        while(temp->link->link != NULL){//while(temp->link != NULL){ 
        
            temp = temp->link;          // prev = temp;

            next = next->link;          // temp = temp->link;

        }
        temp->link = NULL;             // prev->link = NULL;
        free(next);                    //free(temp);

    }

}
void delete_specified(int pos){ 
        struct node *ptr = head, *prev = NULL;  
        
        // ptr=head;  
        for(int i=0;i<pos-1;i++)  
        {  
            prev = ptr;       
            ptr = ptr->link;  
              
            if(ptr == NULL)  
            {  
                printf("\nThere are less than %d elements in the list..\n",pos);  
                return;  
            }  
        }  
        prev ->link = ptr ->link;  
        free(ptr);  
    }     
int main(){
    
    do{
        printf("\n1.INSERT\n2.DELETE AT BEGINING\n3.DELETE AT END\n4.DELETE AT SPECIFIC\n5.TRAVERSAL\n");
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
            delete_begin();
            break;
        case 3:
            delete_end();
            break;
        case 4:
            int pos ;
            printf("Enter the position = \t");
            scanf("%d",&pos);
            delete_specified(pos);
            break;
        case 5:
            printf("The final linked list is = \n");
            traversal();
            break;


        
        default:
            break;
        }

    }while(1);

return 0;
}
