/*
INPUT 
n [one number]

OUTPUT
n*n matrix from 1 to n*n in a spriral form

Example:
input
4

output
1   2   3   4   -------------
12  13  14  5   |-----------|   
11  16  15  6   ||---------||
10  9   8   7   ------------|

*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int print_spiral(int *arr,int n){
    int i,index=0;
    int m=sqrt(n);
    int matrix[m][m];
    int top=0,bottom=m-1,left=0,right=m-1;

    while (1)
    {
        //first row
        for(i=left;i<=right;i++)
             matrix[top][i]=arr[index++];
        top++;

        if(top>bottom)
            break;

        //last column
        for(i=top;i<=bottom;i++)
            matrix[i][right]=arr[index++];
        right--;

        if(left>right)
            break;

        for(i=right;i>=left;i--)
            matrix[bottom][i]=arr[index++];
        bottom--;

        if(top>bottom)
            break;

        for(i=bottom;i>=top;i--)
            matrix[i][left]=arr[index++];
        left++;

        if(left>right)
            break;

    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

}
int main(){

    int n,k=1;
    char dir='r';
    int *arr;
    scanf("%d",&n);//check whether it is perfect square or not
    int sqr=sqrt(n);
    if((int)sqr != sqr){
        printf("INVALID INPUT");
    }
    arr=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        *(arr+i)=k++;
    }
    print_spiral(arr,n);
    return 0;
}