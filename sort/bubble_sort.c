#include<stdio.h>
#define size 1000
void swap(int*a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
//time complexity O(n^2)
// space complexity O(1)
void bubble_sort(int arr[] , int n){
    for(int step = 1 ; step < n ; step++){
        for(int j = 0 ; j<=n-step-1; j++){
            if(arr[j] > arr[j+1] ){
                swap(&arr[j] , &arr[j+1]);
            }
        }
    }
}
int main(){
     int arr[size], size_array;
    printf("Enter how many  number you want to insert : ");
    scanf("%d",&size_array);
    printf("The  entered elements are : \n");
    for(int i = 0 ; i<size_array; i++){
        scanf("%d",&arr[i]);
    }
    printf("The array is = \n");
    for(int i = 0 ; i<size_array; i++){
        printf("%d\t", arr[i]);
    }

   
    bubble_sort(arr,size_array);
    printf("\n The sorted array in ascending order is : \n");
    for(int i = 0 ; i<size_array; i++){
        printf("%d\t", arr[i]);
    }

return 0;
}