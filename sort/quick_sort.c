#include<stdio.h>
#define size 1000
void swap(int *a , int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[] , int s , int e){
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1 ; i<=e ; i++){
        if(arr[i]<= pivot){
            count++;
        }



    }
    int pivotindex = s+count;
    swap(&arr[pivotindex] , &arr[s]);
    int i = s; 
    int j = e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(arr[i] > pivot && arr[j]< pivot){
            swap(&arr[i++] , &arr[j--]);
        }
    }
    return pivotindex;



}
// time complexity O(nlogn)
// space complexity O(n)
void quick_sort(int arr[], int low , int high){
    if(low >= high){
        return;
    }
    int p = partition(arr,low,high);
    quick_sort(arr,low,p-1);
    quick_sort(arr,p+1,high);

    

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

    quick_sort(arr,0 , size_array-1);
    printf("\n The sorted array in ascending order is : \n");
    for(int i = 0 ; i<size_array; i++){
        printf("%d\t", arr[i]);
    }
return 0;
}