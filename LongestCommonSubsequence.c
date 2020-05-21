#include<stdio.h>
#include<string.h>
int dp[100][100];
int max(int a,int b){
    return a>b?a:b;
}
int print(int i,int j,char str1[],char str2[]){
    if(i==0 || j==0){
        return 0;
    }
    if(str1[i-1]==str2[j-1]){
        print(i-1,j-1,str1,str2);
        printf("%c",str1[i-1]);
    }
    else{
        if(dp[i][j-1]>=dp[i-1][j]){
            print(i,j-1,str1,str2);
        }
        else{
            print(i-1,j,str1,str2);
        }
    }

}
int main()
{
    char str1[1000];
    char str2[1000];
    scanf("%s %s",str1,str2);
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    int i=n1,j=n2;
   print(i,j,str1,str2);
}