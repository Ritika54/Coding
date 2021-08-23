#include<stdio.h>
#include<math.h>

int main(){

    int n;
    int root,low_sq,up_sq;
    scanf("%d",&n);
    root = sqrt(n);

    low_sq=root*root;
    if(low_sq == n)
        low_sq=(root-1)*(root-1);
    
    up_sq=(root+1)*(root+1);

    if((up_sq-n)>(n-low_sq))
        printf("%d\n",low_sq);
    else
        printf("%d\n",up_sq);
    
    return 0;
}