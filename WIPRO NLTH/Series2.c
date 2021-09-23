/*
Find Nth term of following series
3 3 0 6 1 9 1 9 2 27 3 12 5 81 8 15 13 243.....
here this series is combination of 2 series
I  = 3 6 9 12 15....(AP)(1 4 8 12 16... terms)
II = 3 9 27 81 243 729....(GP)(2 6 10 14 18 22...terms)
III= 0 1 1 2 3 5 8 13 (Fibonacci Series)(3 5 7 9 11 13...terms)
So,
here we can deduce that if we are given any 
(i)multiple of 4
   let, n=20
   term=(n/4)
   => term = 5+1
   => 6th term of I AP
   '.' we know that 
   Tn=a1+(n-1)*d
   here we can write Tn as a1+((n/4)+1-1)*3 => (12+3*n)/4
   Tn=3+(6-1)*3 = 18

(ii)multiple of 2 but not 4
   let, n=22
   term=(int) (n/4)
   => term = 5+1
   => 6th term of II AP
   '.' we know that 
   Tn=a1*(r)^(n-1)
   here we can write Tn as a1*(3)^((n/4)+1-1) => 3^((n/4)+1)
   Tn=3*(3)^(6-1) = 729

(iii)odd terms except 1
   let, n=9
   term=(int) (n/2)
   => term = 4
   => 4th term of II AP
   '.' we know that 
   0 1 1 2
   so,Tn = 2


*/
#include<stdio.h>
#include<math.h>
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
    int Tn;
    scanf("%d",&n);
    if(n==1 || n==2){
        Tn=3;
    }
    else if(n%4==0){//I series
        Tn=(12+3*n)/4;
    }
    else if(n%2==0){//II series
        Tn=pow(3,((int)(n/4))+1);
    }
    else{//III series
        n=n/2;
        Tn=fibo(n);
    }
    printf("%d",Tn);
    return 0;
}