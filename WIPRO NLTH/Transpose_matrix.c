#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,j,n,deg;
    int *matrix;
    
    scanf("%d",&n);
    matrix = (int *)malloc(n*n*sizeof(int));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",((matrix+i)+j));
        }   
    }

    scanf("%d",&deg);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",(*(matrix+i)+j));
        }   
        printf("\n");
    }

    if(deg==90){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d\t",(*(matrix+j)+i));
            }
            printf("\n");
        }
    }
    else if(deg==-90 || deg==270){
        for(i=0;i<n;i++){
            for(j=n-1;j>=0;j--){
                printf("%d\t",(*(matrix+j)+i));
            }
            printf("\n");
        }
    }
    else if(deg==180){
        for(i=n-1;i>=0;i--){
            for(j=0;j<n;j++){
                printf("%d\t",(*(matrix+i)+j));
            }
            printf("\n");
        }
    }
    else{
        printf("invalid input");
    }
    return 0;
}