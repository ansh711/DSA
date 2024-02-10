
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *st = NULL;
struct node *create_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void insertion_head(int data)
{
    struct node *temp = create_node(data);
    if (st == NULL)
    {
        st = temp;
        return;
    }
    else
    {
        st->prev = temp;
        temp->next = st;
        st = temp;
    }
}
void insertion_end(int data)
{
    struct node *temp = create_node(data);
    if (st == NULL)
    {
        st = temp;
        return;
    }
    else
    {
        struct node *temp1 = st;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }
}
void insertion_specific(int data, int n)
{
    struct node *temp = create_node(data);
    if (n == 1)
    {
        st->prev = temp;
        temp->next = st;
        st = temp;
        return;
    }
    else
    {
        struct node *temp1 = st;
        for (int i = 0; i < n - 2; i++)
        {

            temp1 = temp1->next;
        }

        temp->prev = temp1;
        temp->next = temp1->next;
        temp1->next = temp;
    }
}
void deletion(int n)
{
    struct node *temp = st;
    if (n == 1)
    {
        st = temp->next;
        // temp->next->prev = NULL;
        free(temp);
        return;
    }
    else
    {
        struct node *temp1 = temp->next;
        for (int i = 0; i < n - 2; i++)
        {
            temp = temp->next;
        }
        temp->next = temp1->next;
        // temp1->next->prev= temp;
        free(temp1);
    }
}
void reverse()
{
    struct node *next, *current = st, *prev = NULL;
    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != NULL);
    st = prev;
}
void print()
{
    struct node *temp = st;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != NULL);
    printf("\n");
}
// void reverse_print()
// {
//     struct node *temp = st;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }

//     do
//     {
//         printf("%d\t", temp->data);
//         temp = temp->prev;
//     } while (temp != NULL);
//     printf("\n");
// }
int main()
{
    do
    {
        int ch;
        printf("1. Insert at head position \n 2. Insert at the end \n 3. Insert at the specific position \n  4. reverse the list \n 5. print \n 6.  deletion\n");
        printf("Enter your choice =");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            int item;
            printf("Enter the number you want to insert = ");
            scanf("%d", &item);
            insertion_head(item);
            break;
        case 2:
            int item1;
            printf("Enter the number you want to insert = ");
            scanf("%d", &item1);
            insertion_end(item1);
            break;
        case 3:
            int item2, a;
            printf("Enter the number you want to insert = ");
            scanf("%d", &item2);
            printf("Enter the position you want to insert = ");
            scanf("%d", &a);
            insertion_specific(item2, a);
            break;
        case 4:
            reverse();
            break;
        case 5:
            print();
            break;
        case 6:
            
            int x;
            printf("Enter the position from where  you want to delete the element  = ");
            scanf("%d", &x);
            deletion(x);
            break;
        default:
            printf("VERIFY YOUR CHOICE AGAIN \n");
            break;
        }
    } while (1);

    return 0;
}