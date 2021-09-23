#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
        char temp = *a;
        *a = *b;
        *b = temp;
}
int palindrome(char *str)
{
        int i,j;
        i = 0;
        j = 0;
        while(str[j]!='\0')
                j++;
        j--;
        while(i<j)
                if(str[i++] != str[j--])
                        return 0;
        return 1; //palindrome
}
void permutate(char *str, int start_index, int end_index)
{
        int i;
        static int flag = 0;
        if(flag==1)
                return;
        for(i=start_index;i<=end_index;i++)
        {
                if(start_index == end_index)
                {
                        if(palindrome(str))
                        {
                                printf("Palindrome\n");
                                flag = 1;
                                return;
                        }
                }
                else
                {
                        swap(str+start_index,str+i);
                        permutate(str,start_index+1,end_index);
                        swap(str+start_index,str+i);
                }
        }
        printf("Not a Palindrome");
}
int main(){
    char str[20];
    scanf("%[^\n]%*c",str);
    int l=strlen(str);
    permutate(str,0,l-1);
    return 0;
}