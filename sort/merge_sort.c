#include<stdio.h>
#define size 1000


//space complexity O(n)
// time complexity O(nlogn)
void merge(int arr[] , int low , int high){
    int mid = low +(high- low)/2;
    int len1 = mid - low +1;
    int len2 = high - mid;
    int l[len1];
    int m[len2];
    int mainarrayindex = low;
    for (int i=0 ;i < len1 ; i++){
        l[i] = arr[mainarrayindex++];
    }
     mainarrayindex = mid+1;
    for (int i=0 ;i < len2; i++){
        m[i] = arr[mainarrayindex++];
    }
    int i = 0, j = 0;
    mainarrayindex = low;
    while ((i < len1) && (j < len2)){
        if(l[i] <= m[j]){
            arr[mainarrayindex++] = l[i++];
        }
        else{
            arr[mainarrayindex++] = m[j++];
        }
    }
    while(i< len1){
        arr[mainarrayindex++] = l[i++];
    }
    while(j< len2){
        arr[mainarrayindex++] = m[j++];
    }
}
void merge_sort(int arr[], int low  , int high){

    // int low = 0;
    // int high = n-1;
    if(low>=high){
        return;
    }
    int mid = low + (high-low)/2;
    merge_sort(arr,low , mid);
    merge_sort(arr , mid+1 , high);

    merge(arr , low , high);


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

    merge_sort(arr,0,size_array-1);
    printf("\n The sorted array in ascending order is : \n");
    for(int i = 0 ; i<size_array; i++){
        printf("%d\t", arr[i]);
    }
return 0;
}