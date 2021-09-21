/*
1 2 3 4 5 4 3 2 1
1 2 3 4   4 3 2 1
1 2 3       3 2 1
1 2           2 1
1               1
*/

//NOTE: Ascending -> convert it to i
//NOTE: Descending -> convert it to n

//ASCENDING
/*
line(i)     Number(j<=n-i+1)
1           12345
2           1234
3           123
4           12
5           1
*/
//SPACES
/*
line spaces
1      -1
2       1
3       3
4       5
5       7

Find nth term of space Arithmatic Progression
FORMULA : an=a1+(n-1)*d
an=-1+(line-1)*2 
an=2*line-3
*/

//DESCENDING
/*
line(i)     Number(j=n-i+1)
2           4321
3            321
4             21
5              1
*/
#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        //Acsending
        for(int j=1;j<=n-i+1;j++)
            printf("%d",j);
            
        //space
        for(int j=1;j<=2*i-3;j++)
            printf(" ");

        //Descending
        if(i==1){
            for(int j=4;j>=1;j--)
                printf("%d",j);
        }
        else{//From 2nd line onwards
            for(int j=n-i+1;j>=1;j--)
                printf("%d",j);
        }
        printf("\n");
    }

    return 0;
}
