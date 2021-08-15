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

int lengthOfInteger(int a){

    int l=0;
    while(a){
        a/=10;
        l++;
    }
    return l;
}

void palindrome(int a, int b){
    int i, rev;//,l,key;
    //l=lengthOfInteger(a);
        
    for(int j=a;j<=b;j++){
        // key=l/2;
        // if(i>=100-a)
        //     l=lengthOfInteger(j);
        
        i=j;
        rev=0;

        while(i/*key*/){
            rev= rev*10 + i%10;
            i=i/10;
    //        key--;
        }
        
        if(j/*i*/==rev)
            printf("%d\n",j);
    }
}

int main(){

    int a,b;
    printf("hello");
    scanf("%d %d",&a,&b);
    palindrome(a,b);
    return 0;
}