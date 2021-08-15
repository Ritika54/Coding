#include<stdio.h>

int main(){

    int virus_arr[26]={0};
    char *vir_comp,*blood_comp[10];
    int n,i;

    scanf("%ms",&vir_comp);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%ms",&blood_comp[i]);

    for(i=0;vir_comp[i]!='\0';i++)
        virus_arr[vir_comp[i]-97]=1;
    
    for(i=0;i<n;i++){
        int flag=0;
        for (int j = 0; blood_comp[i][j]!='\0'; j++)
        {
            if (virus_arr[blood_comp[i][j]-97]==0)
            {
                printf("NEGATIVE\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("POSITIVE\n");
        
    }
    return 0;
}