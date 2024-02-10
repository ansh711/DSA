#include<stdio.h>
#define size  1000
void swap(int*a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
// time complexity = O(n^2)
// space complexity = O(1)
void selection_sort(int arr[] , int n){
    for(int i =0 ; i< n; i++){
        int min = i;
        for(int j = i+1 ; j<n ; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
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

   
    selection_sort(arr,size_array);
    printf("\n The sorted array in ascending order is : \n");
    for(int i = 0 ; i<size_array; i++){
        printf("%d\t", arr[i]);
    }

return 0;
}