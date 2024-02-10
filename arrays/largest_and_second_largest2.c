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
    static int max1 , max2;
    if(arr[1] > arr[0] ){
        max1 = arr[1];
        max2 = arr[0];
    }
    else{
        max1 = arr[0];
        max2 = arr[1];

    }
    for (int i = 2; i < n; i++)
    {
        /* code */
        if(arr[i] > max1){
            max2 = max1;
            max1 = arr[i];
        }
        if(arr[i] > max2 && arr[i]<max1 ){
            max2 = arr[i];
        }
    }
    printf("\nLargest element is %d ",max1);
    printf("\nSecond largest element is %d ",max2);
    
    return 0;
}