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
    int max1 = arr[0] , max2 = arr[0];
    //Finding maximum element using brute force method
    for(int i = 1 ; i < n ; i++){
        if(arr[i] > max1){
            max1 = arr[i];
        }
    }
    for(int i = 0 ; i<n ; i++){
        if(arr[i] > max2 && arr[i]<max1){
            max2=arr[i];
        }
    }
    printf("\n The largest element is %d" , max1);
    printf("\n The second largest element is %d" , max2);
return 0;
}