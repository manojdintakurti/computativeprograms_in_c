#include<stdio.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    int a=2,b=8,c;
    printf("%d %d ",a,b);
    c=4*b+a;
    while(c<=n){
        printf("%d ",c);
        a=b;
        b=c;
        c=4*b+a;
    }
}