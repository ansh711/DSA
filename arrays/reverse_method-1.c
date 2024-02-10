#include<stdio.h>
#define size 100
void swap(int *a , int *b){
    int temp = *a ;
    *a = *b;
    *b = temp; 

}
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
    for (int i = 0; i < n/2; i++)
    {
        /* code */
        swap(&arr[i] , &arr[n-i-1]);
    }
    printf("\nThe array after reversal is = \n");
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d\t" , arr[i]);
    }

    
return 0;
}