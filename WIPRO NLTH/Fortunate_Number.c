/*
A fortunate number is the smallest integer > 1 such that, 
for a given positive integer n, pn+m is a prime number.
pn is the product of first n prime number

Example :
Input
3
Output
7

Explaination 
first 3 prime numbers are 2,3,5
their product = 30
fortunate would be here 7,since (30+7) is a prime number
*/

#include<stdio.h>
#include<math.h>

int prime(int a){
    
    int sqr=sqrt(a);
    for(int i=2;i<=sqr;i++){
        if(a%i == 0)
            return 0;
    }
    
    return 1;
}

int product_prime(int a){

    int num=2,product=1;
    while(a){
        if(prime(num)){
            product*=num;
            a--;
        }
        num++;
    }
    
    return product;
}

int main(){

    int a,i=2;
    scanf("%d",&a);
    
    a=product_prime(a);
    
    while(!(prime(a+i)))
        i++;
    printf("%d",i);
    
    return 0;
}