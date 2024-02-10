#include<stdio.h>
#define size 100

int main(){
    int n , arr[size];
    printf("Enter the number of elements you want in array : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        scanf("%d",&arr[i]);
    }
    printf("The array given is = \n");
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d\t",arr[i]);
    }
    int index ;
    printf("\nEnter the position where the element is to be inserted  for : ");
    scanf("%d",&index);
    int item ;
    printf("Enter the element which has to be inserted : ");
    scanf("%d",&item);
    for (int i = n-1; i >= index; i--)
    {
        /* code */
        arr[i+1] = arr[i];


    }
    
    arr[index]=item;
    n = n+1;

    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d\t",arr[i]);
    }
    
    
    
    

return 0;
}