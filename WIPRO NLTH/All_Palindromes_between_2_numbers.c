/*
Printing all palindrome number between two given number.
Input 
50 100
Output
55
66
77
88
99

Above printed are the palindrome numbers between given number 50 and 60.
*/
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