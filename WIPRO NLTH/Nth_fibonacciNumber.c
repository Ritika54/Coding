/*
To find Nth Fibonacci Number
0 1 1 2 3 5 8 13........
*/
#include<stdio.h>
#include<math.h>
//returns nth fibonacci number
int fibo(int n){
    if(n==1)
        return 0;
    if(n==2 || n==3)
        return 1;
    int first=1,second=1,sum=first+second;
    for(int i=1;i<=n-4;i++){
        sum=first+second;
        first=second;
        second=sum;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fino(n));
    return 0;
}