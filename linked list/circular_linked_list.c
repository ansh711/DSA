#include<stdio.h>
#include<stdlib.h>
struct node
{
    /* data */
    int data;
    struct node* link;
};
struct node* head = NULL;
void traverse(struct node * head){
    struct node *temp = head; 
 
    
    if (head != NULL) 
    {
       
        do
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        while (temp != head);
    }
}

void insertion(int key , int pos){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->link = NULL;
    if(pos == 1){
        if(head == NULL){
            head = temp;
            temp->link = head;
            return;
        }
        else{
            temp->link = head;
            head = temp;
            return;
        }
    }

    else{
        struct node* ptr = head;
        for (int i = 1; i <= pos-2; i++)
        {
            /* code */
            ptr = ptr->link;
        }
        if(ptr->link == head){
            ptr->link = temp;
            temp->link = head;
            return;
        }
        else{
            temp->link = ptr->link;
            ptr->link = temp;
        }
        
    }
}

void deletion(int key){
    if(head == NULL) return;
    struct node * curr = head , *prev = NULL;
    while(curr->data != key){
        if(curr->link == head){
            printf("The list doesn't contain the given element\n");
            return;
        }
        else{
            prev = curr;
            curr = curr->link;
        }
    }
    if(curr->link == head){
        prev->link = head;
        free(curr);
        return;
    }
    if(curr == head){
        prev = head;
        while(prev->link != head) prev = prev->link;
        head = curr->link;
        prev->link = head;
        free(curr);
    }
    else if(curr->link == head && curr == head){
        prev->link = head;
        free(curr);
    }
    else{
        prev->link = curr->link;
        free(curr);
    }

}

int main(){
     do
    {
        int ch;
        printf("1. Insertion \n 2.Deletion \n 3. Traverse\n ");
        printf("Enter your choice =");
        scanf("%d", &ch);
        switch (ch)
        {
        
        case 1:
            int item1,pos;
            printf("Enter the number you want to insert = ");
            scanf("%d", &item1);
            printf("\n Enter the position where you want to insert it = ");
            scanf("%d",&pos);
            insertion(item1,pos);
            break;
        case 2:
            int item2;
            printf("Enter the number you want to delete = ");
            scanf("%d", &item2);
            
            deletion(item2);
            break;
        case 3:
            traverse(head);
            break;
        
        default:
            printf("VERIFY YOUR CHOICE AGAIN \n");
            break;
        }
    } while (1);

return 0;
}