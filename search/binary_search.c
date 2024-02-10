#include<stdio.h>
#define size 1000
void swap(int*a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
// time complexity = O(n^2)
// space complexity = O(1)
void selection_sort(int arr[] , int n){
    for(int i =0 ; i< n-1; i++){
        int min = i;
        for(int j = i+1 ; j<n ; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}
int binary_search(int arr[] , int n , int key,int low , int high){
    // int low = 0;
    // int high = n-1;
    while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
      return mid;

    if (arr[mid] < key)
      low = mid + 1;

    else
      high = mid - 1;
    } 
    return -1;

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

    printf("\nThe sorted array is =\n ");
    for(int i = 0 ; i<size_array; i++){
        printf("%d\t", arr[i]);
    }

    int element ;
    printf("\nEnter the element you want to search = ");
    scanf("%d",&element);
   


    int low = 0;
    int high = size_array-1;
    
    int result = binary_search(arr, size_array, element,low , high) ;
    
    if(result == -1){
        printf("NOT FOUND\n");
    }
    else{
        printf("The elemnent is found in the position %d\n",result+1);
    }


return 0;
}