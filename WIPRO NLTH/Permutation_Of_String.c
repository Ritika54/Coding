#include<stdio.h>
#include<string.h>
void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
void permute(char* str,int start_index,int end_index){
    for(int i=start_index;i<=end_index;i++){
        if(start_index==end_index)
            printf("%s\n",str);
        else{
            swap(str+start_index,str+i);
            permute(str,start_index+1,end_index);
            swap(str+start_index,str+i);
        }
    }
}
int main(){
    char str[20];
    scanf("%[^\n]%*c",str);
    int l=strlen(str);
    permute(str,0,l-1);
    return 0;
}