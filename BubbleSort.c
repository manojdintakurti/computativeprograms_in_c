#include<stdio.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int iter = 2,i=0,temp;
    while(n-iter>0){
        i=0;
        while(i<=n-iter){
            if(arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
            i++;
        }
        iter++;
    }
    for(i=0;i<n;i++){
        printf("%lld ",arr[i]);
    }
}