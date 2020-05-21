#include<stdio.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int iter = 1,i=n-1,temp;
    while(iter<n-1){
        i=n-1;
        while(i>=iter){
            if(arr[i]<arr[i-1]){
                temp=arr[i];
                arr[i]=arr[i-1];
                arr[i-1]=temp;
            }
            i--;
        }
        iter++;
    }
    for(i=0;i<n;i++){
        printf("%lld ",arr[i]);
    }
}