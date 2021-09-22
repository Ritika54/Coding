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
        int k=1;
        for(int j=1;j<=cols;j++){
            if(j>=n-i+2 && j<=n+i-2)
                printf(" ");
            else
                printf("%d",k);
            (j<n)?k++:k--;
        }
        printf("\n");
    }
    return 0;
}