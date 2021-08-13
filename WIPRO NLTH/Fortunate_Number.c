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
    
    if(a==2)
        return 1;
        
    if(a%2==0)
        return 0;

    int sqr=sqrt(a);
    for(int i=3;i<=sqr;i+=2){
        if(a%i == 0)
            return 0;
    }
    
    return 1;
}

int product_prime(int a){

    if(a==0)
        return 0;
    if(a==1)
        return 2;

    int num=3,product=2;
    /*
    Since num here is 3 and we are incrementing it by 2. 
    This means we are only checking for odd numbers, because other than 2, 
    no even number is prime.
    That's why we have already considered 2 in the product if a>1
    */
   --a;
    while(a){
        if(prime(num)){
            product*=num;
            a--;
        }
        num+=2;        
    }
    
    return product;
}

int main(){

    unsigned int a,i=2;
    scanf("%u",&a);//since 'a' is a count of number for which we have to product,so cannot be negative 
    
    a=product_prime(a);
    
    while(!(prime(a+i)))
        i++;
    printf("%d",i);
    
    return 0;
}