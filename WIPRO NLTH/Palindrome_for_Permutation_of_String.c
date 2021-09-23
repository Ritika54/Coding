#include<stdio.h>
#include<string.h>
void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
int palindrome(char *str){
    int l =strlen(str);
    for(int i=0,j=l-1;i<=(l/2);i++,j--){
        if(str[i]!=str[j])
            return 0;
    }
    return 1;
}
void permute(char* str,int start_index,int end_index){
    static int flag = 0;
        if(flag==1)
                return;
    for(int i=start_index;i<=end_index;i++){
        if(start_index==end_index){
            if(palindrome(str)){
                printf("Palindrome\n");
                flag = 1;
                return;
            }    
        }
        else{
            swap(str+start_index,str+i);
            permute(str,start_index+1,end_index);
            swap(str+start_index,str+i);
        }
    }
    printf("Not a Palindrome");
}
int main(){
    char str[20];
    scanf("%[^\n]%*c",str);
    int l=strlen(str);
    permute(str,0,l-1);
    return 0;
}