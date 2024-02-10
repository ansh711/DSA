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
    int low = 0;
    int high = n-1;
    while(low <= high){
        swap(&arr[low] , &arr[high]);
        low++;
        high--;
    }
    printf("\nThe array after reversal is = \n");
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d\t" , arr[i]);
    }

return 0;
}