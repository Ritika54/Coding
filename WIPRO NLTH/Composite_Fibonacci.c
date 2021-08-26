/*
This program checks whether the number in the array is composite 
as well as fibonacci number
Example: 
INPUT
arr = {1,2,3,4,5,6,7,8}

OUTPUT
8
//Since 8 is the only number in the array which is composite
as well as fibonacci number
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int prime(int n){
    if(n==0 || n==1)
        return 1;//Since 1 is neither prime nor composite
    int sqr=sqrt(n);
    for(int i=2;i<=sqr;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
// int fibo(int n){
//     if(n<0)//fibonacci series doesnot have negative numbers
//         return 0;
//     int first=0,second=1;
//     for(int i=0;i<n;i++){
//         if(n==first || n<first)
//             return 1;
//         int sum=first+second;
//         first=second;
//         second=sum;
//     }
//     return 0;
// }
// void fiboArr(int *arr,int size,int max){

//     printf("\nentered function\n");
//     int *fibo;
//     fibo=(int *)malloc(max*sizeof(int));
//     int first=0,second=1,sum=0,i=0;

//     while(first <= max){	//0,1,1,2,3,5,8,13
//         *(fibo+i)=first;
//         sum=first+second;
//         first=second;
//         second=sum;
//         i++;
//     }
    
//     int flag=0;
//     for(int j=0;j<size;j++){
//         if(!(prime(*(arr+j)))){
//             for(int k=0;*(arr+j)>=*(fibo+k);k++)/* Since we know that 0,1 are not composite, that's why we are not 
//                                  checking array with first three fibonacci number */
//                 if(*(arr+j) == *(fibo+k)){
//                     printf("%d\t",*(arr+j));
//                     flag++;
//                 }
//         }
//     }
//     if(flag==0)
//         printf("None of the numbers of array satisfy both the conditions of being composite and fibonacci number");

// }

int main(){

    int *arr;
    int n,max,fibo[100];
    scanf("%d",&n);

    arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",(arr+i));
        if(*(arr+i)>max)
            max=*(arr+i);
    }

    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;fibo[i-1]<max;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
        
    for(int i=0;i<n;i++){
        if(!prime(arr[i])){
            for(int l=0;arr[i]>=fibo[l];l++){
                if(arr[i]==fibo[l]){
                    printf("%d\t",arr[i]);
                }
            }
        }
    }
    //fiboArr(arr,n,max);
    return 0;
}