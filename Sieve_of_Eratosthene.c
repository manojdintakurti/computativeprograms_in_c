#include<stdio.h>
#include<math.h>
int main()
{
long long int n;
scanf("%lld",&n);
long long int arr[n-1];
for(long long int i=0;i<n-1;i++){
    arr[i]=i+2;
}
for(long long int i=0;arr[i]<=sqrt(n);i++){
    if(arr[i]!=0){
        for(long long int j=i+arr[i];j<n-1;j=j+arr[i]){
            arr[j]=0;
        }
    }
}
for(long long int i=0;i<n-1;i++){
    if(arr[i]!=0){
        printf("%lld ",arr[i]);
    }
}
}