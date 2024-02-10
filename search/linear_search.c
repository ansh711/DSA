#include<stdio.h>
#define size 1000
void linear_search(int key,int arr[],int n){
    
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == key){
            printf("The  element is present at position %d\n",i+1);
            return;
        }
       
    }
    printf("The element is not found in the array\n");

}
int main(){
    int arr[size] , size_array;
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

    int element ;
    printf("Enter the element you want to search = ");
    scanf("%d",&element);


    
    int n = sizeof(arr)/sizeof(arr[0]);
    linear_search(element,arr,n);

return 0;
}