/*
Find Nth term of following series
3 3 6 9 9 27 12 81 15.....
here this series is combination of 2 series
I=3 6 9 12 15....(AP)(odd terms)
II=3 9 27 81....(GP)(Even terms)
So,
here we can deduce that if we are given any 
(i)odd term to find
   let, n=7
   term=(n+1/2)
   => term = 4
   => 4th term of I AP
   '.' we know that 
   Tn=a1+(n-1)*d
   Tn=3+(4-1)*3 = 12

(ii)even term to find
   let, n=6
   term=(int) (n/2)
   => term = 3
   => 3rd term of II AP
   '.' we know that 
   Tn=a1*(r)^(n-1)
   Tn=3*(3)^(3-1) = 27

*/
#include<stdio.h>
#include<math.h>
int main(){
    int n;
    int Tn;
    scanf("%d",&n);
    if(n%2==0){
        n=n/2;//No need to do this if we use statement written in comment
        Tn=3*pow(3,n-1);//Tn=(int)pow(3,n/2)
    }
    else{
        n=(n+1)/2;//No need to do if we use 2nd statement written in comment 
        Tn=3+(n-1)*3;//Tn=n*3 or Tn=(int)(3*n-3)/2
    }
    printf("%d",Tn);
    return 0;
}