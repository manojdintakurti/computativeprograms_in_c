#include<stdio.h>
void merge(int arr[],int start,int mid,int end){
    int n1 = mid-start+1;
    int n2 = end-mid;
    int L[n1],R[n2],i=0,j=0;
    for(int k=start;k<=mid;k++){
        L[i]=arr[k];
        i++;
    }
    for(int k=mid+1;k<=end;k++){
        R[j]=arr[k];
        j++;
    }
    i=0;
    j=0;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[start]=L[i];
            i++;
            start++;
        }
        else{
            arr[start]=R[j];
            j++;
            start++;
        }
    }
    while(i<n1){
        arr[start]=L[i];
        i++;
        start++;
    }
    while(j<n2){
        arr[start]=R[j];
        j++;
        start++;
    }
}
void mergeSort(int arr[],int start,int end){
    int mid = (start+end)/2;
    if(start<end){
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum;
    scanf("%d",&sum);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int start=0,end=n-1;
    while(start<end){
        if((arr[start]+arr[end])==sum){
            printf("(%d,%d) ",arr[start],arr[end]);
            start++;
            end--;
        }
        else if((arr[start]+arr[end])>sum){
            end--;
        }
        else if((arr[start]+arr[end]<sum)){
            start++;
        }
    }
}