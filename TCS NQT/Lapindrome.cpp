/*
Check whether a given string is Lapindrome or not.
Lapindrome is a string when divided into two equal halves, 
the left part and right part are anagrams(same characters but in different order) of eachother.

Example :
Input
noononon 
heartiearth

Output
Lapindrome 
Lapindrome

Explaination
noon is anagram of onon
heart is anagram of earth

*/
#include<iostream>
#include<string.h>
using namespace std;

int main(){

    int alpha[26]={0};
    char *str;
    cin>>str;
    int l=strlen(str);
    int half;
    if(l%2!=0)
        half=l/2;
    else
        half=l/2 -1;
    cout<<l<<" "<<half;
    for(int i=0;i<=half;i++){
        if(str[i]>=65  && str[i]<=90)
            ++alpha[str[i]-'A'];
        else if(str[i]>=97  && str[i]<=122)
            ++alpha[str[i]-'a'];
    }
    for(int j=half;j<l;j++){
        if(str[j]>=65  && str[j]<=90)
            --alpha[str[j]-'A'];
        else if(str[j]>=97  && str[j]<=122)
            --alpha[str[j]-'a'];
    }
    int flag=0;
    for(int k=0;k<26;k++){
        if(alpha[k]!=0){
            flag=1;
            cout<<"Entered string is not a lapindrome";
            break;
        }
    }
    if(flag==0){
        cout<<"Entered string is lapindrome";
    }

    return 0;
}