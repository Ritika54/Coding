#include<stdio.h>

void palindrome(int a, int b){
    int i, rev;
    for(int j=a;j<=b;j++){
        i=j;
        rev=0;

        while(j){
            rev= rev*10 + j%10;
            j=j/10;
        }
        
        if(i==rev)
            printf("%d\n",i);
    }
}

int main(){

    int a,b;
    scanf("%d %d",&a,&b);
    palindrome(a,b);
    return 0;
}