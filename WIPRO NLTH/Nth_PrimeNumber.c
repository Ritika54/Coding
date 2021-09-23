#include<stdio.h>
#include<math.h>
//checks whether n is prime 
int prime(int n){
    int sqr=sqrt(n);
    if(n==2)
        return 1;
    if(n%2==0)
        return 0;
    for (int i = 3; i <= sqr; i+=2){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    int i=1;
    scanf("%d",&n);
    while(n!=0){
        i++;
        if(prime(i)){
            n--;
        }
    }
    printf("%d",i);
    return 0;
}