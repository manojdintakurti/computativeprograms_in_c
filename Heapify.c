#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int heap[n+1];
    int i=1;
    scanf("%d",&heap[i]);
    i++;
    int k;
    while(i<=n){
        scanf("%d",&heap[i]);
        k=i;
        while(k>1){
            if(heap[k]>heap[k/2]){
                int temp=heap[k];
                heap[k]=heap[k/2];
                heap[k/2]=temp;
                k=k/2;
            }
            else{
                break;
            }
        }
        i++;

    }
    for(int i=1;i<=n;i++){
        printf("%d ",heap[i]);
    }
    int len=n;
    while(len>1){
        int temp=heap[1];
        heap[1]=heap[len];
        heap[len]=temp;
        len--;
        k=1;
        while(2*k<=len){
            if(2*k+1<=len){
                if(heap[2*k]>heap[2*k+1]){
                    if(heap[2*k]>heap[k]){
                        int temp=heap[k];
                        heap[k]=heap[2*k];
                        heap[2*k]=temp;
                        k=2*k;                    
                        }
                
                else{
                    break;
                }

                }
                else{
                    if(heap[2*k+1]>heap[k]){
                        int temp=heap[k];
                        heap[k]=heap[2*k+1];
                        heap[2*k+1]=temp;
                        k=2*k+1;                    
                        }
                
                else{
                    break;
                }
                }
            }
            else{
                if(heap[2*k]>heap[k]){
                        int temp=heap[k];
                        heap[k]=heap[2*k];
                        heap[2*k]=temp;
                        k=2*k;                    
                        }
                
                else{
                    break;
                }
            }
        }

    }
    printf("\n");
    for(int i=1;i<=n;i++){
        printf("%d ",heap[i]);
    }
}