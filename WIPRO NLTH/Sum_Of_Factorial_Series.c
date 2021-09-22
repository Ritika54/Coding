/*
sum=1+2+6+24+120+......+n
=>sum=1!+2!+3!+4!+5!+......
*/
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int sum=0,fact=1;
    for(int i=1;i<=n;i++){
        fact=1;
        for(int j=1;j<=i;j++){
            fact*=j;
        }
        sum+=fact;
    }
    printf("%d",sum);
    return 0;
}