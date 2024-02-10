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
    n = n-1;
    printf("\n");
    printf("After deletion from the end the array is = \n");
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d\t",arr[i]);
    }
return 0;
}