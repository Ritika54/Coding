#include<stdio.h>

void palindrome(int a, int b){
    int i, rev;
    for(int j=a;j<=b;j++){
        i=j;
        rev=0;

        while(i){
            rev= rev*10 + i%10;
            i=i/10;
        }
        
        if(j==rev)
            printf("%d\n",j);
    }
}

int main(){

    int a,b;
    scanf("%d %d",&a,&b);
    palindrome(a,b);
    return 0;
}