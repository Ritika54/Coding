/*
1 2 3 4 5 D C B A
1 2 3 4   D C B A
1 2 3       C B A
1 2           B A
1               A
*/

#include<stdio.h>

int main(){

    int n;
    int cols;
    scanf("%d",&n);
    cols=2*n - 1;
    int skipn=5,skipc=5;
    for(int i=1;i<=n;i++){
        char z='D';
        for(int j=1;j<=cols;j++){
            if(j<=n){
                if(j<=skipn){
                    printf("%d",j);
                }
                else{
                    printf(" ");
                }
            }
            else{
                if(j>=skipc){
                    printf("%c",z);
                }
                else{
                    printf(" ");
                }
                z--;
            }    
        }
        printf("\n");
        skipn--;
        skipc++;
    }    
    return 0;
}
