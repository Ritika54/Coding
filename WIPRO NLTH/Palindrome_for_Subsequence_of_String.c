#include<stdio.h>
#include<string.h>
int palindrome(char *str,int i,int j)
{
        while(i<j)
                if(str[i++] != str[j--])
                        return 0;
        return 1; //palindrome
}
void subSequence(char *str){
    int len =strlen(str);
    int max=len-1;//Maximum length of Substring
    for(int i=2;i<=max;i++){//i=length of subsequence
        for(int j=0;j<=len-i;j++){//j=start index
            if(palindrome(str,j,j+i-1)){        
                for(int k=0;k<i;k++){
                    printf("%c",str[k+j]);
                }
                printf("\t");
            }
        }
        printf("\n");
    }

}
int main(){
    char str[20];
    scanf("%[^\n]%*c",str);
    subSequence(str);
    return 0;
}