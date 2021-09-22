/*
    1
   121
  12321
 1234321
123454321
 bcdedcb
  cdedc
   ded
    e
*/
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int rows,cols;
    rows=2*n-1;
    cols=2*n-1;

    for(int i=1;i<=rows;i++){
        char z=96;
        int k=0;
        int flag=i-n;
        for(int j=1;j<=cols;j++){
            //NUMBERS
            if(i<=n){
                //ASCENDING
                if(j<=n){
                    //SPACES
                    if(j<=n-i)
                        printf(" ");
                    else{//NUMBERS
                        k++;
                        printf("%d",k);
                    }
                }
                //DESCENDING
                if(j>n){
                    //SPACES
                    if(j>=n+i)
                        printf(" ");
                    else{//NUMBERS
                        k--;
                        printf("%d",k);
                    }
                }
            }
            //CHARACTERS
            if(i>n){
                //ASCENDING
                if(j<=n){
                    z++;
                    //SPACES
                    if(j<=i-n)
                        printf(" ");
                    else{//CHARACTERS
                        printf("%c",z);
                    }
                }
                //DESCENDING
                if(j>n){
                    //SPACES
                    if(j>=2*n-flag)
                        printf(" ");
                    else{//CHARACTERS
                        z--;
                        printf("%c",z);
                    }
                }
            }  
        }
        printf("\n");
    }

    return 0;
}