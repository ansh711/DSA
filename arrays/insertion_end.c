#include<stdio.h>

int main(){
    int n = 4;
    int arr[4]={10 , 20  , 40 , 25};
   
    arr[n] = 35;
    n = n+1;
    
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d\t",arr[i]);
    }
    

return 0;
}