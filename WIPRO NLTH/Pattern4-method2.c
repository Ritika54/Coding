/*
123454321
1234 4321
123   321
12     21
1       1
*/
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int cols=2*n-1;
    for(int i=1;i<=n;i++){
        //ASCENDING
        for(int j=1;j<=n-i+1;j++){
            printf("%d",j); 
        }
        //SPACES
        for(int j=1;j<=2*i-3;j++){
            printf(" ");
        }
        //DESCENDING
        if(i==1){
            for(int j=n-i;j>=1;j--)
                printf("%d",j);
        }
        else{
            for(int j=n-i+1;j>=1;j--)
                printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}