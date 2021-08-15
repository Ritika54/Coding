/*
Virus Outbreak

In the Martian land faraway, a new virus has evolved and is attacking the individuals at a fast pace.
The scientists have figured out the virus composition, V. The big task is to identify the people who
are infected. The sample of N people is taken to check if they are POSITIVE or NEGATIVE. A report is
generated which provides the current blood composition B of the person.

POSITIVE or NEGATIVE ?

If the blood composition of the person is a subsequence of the virus composition V, then the person
is identified as POSITIVE otherwise NEGATIVE.

Example:

Virus Composition, V = coronavirus

Blood Composition of the person , B = ravus

The person in question is POSITIVE as B is the subsequence of the V.



The scientists are busy with their research for medicine and request you to build a program which
can quickly figure out if the person is POSITIVE or NEGATIVE. They will provide you with the virus
composition V and all the people’s current blood composition. Can you help them?

Note: The virus and blood compositions are lowercase alphabet strings.

Input Format

The first line of the input consists of the virus composition, V

The second line of he input consists of the number of people, N

Next N lines each consist of the blood composition of the ith person, Bi



Constraints

1<=N<=10

1<= |B|<= |V|<= 10^5


Output Format
For each person, print POSITIVE or NEGATIVE in a separate line

Sample TestCase 1
Input
coronavirus
3
abcde
crnas
onarous
Output
NEGATIVE
POSITIVE
NEGATIVE

*/
#include<iostream>
#include<vector>
using namespace std;

int main(){

    int m,n,temp,i=0,j=0;
    vector<int> a;
    vector<int> b;
    cin>>m>>n;

    for(i=0;i<m;i++){
        cin>>temp;
        a.push_back(temp);
    }
    
    for(i=0;i<n;i++){
        cin>>temp;
        b.push_back(temp);
    }
    
    i=j=0;
    
    while(i<m && j<n){
        if(a[i]<b[j])
            cout<<a[i++]<<"\t";
        else
            cout<<b[j++]<<"\t";
    }

    while(i<m)
        cout<<a[i++]<<"\t";

    while(j<n)
        cout<<b[j++]<<"\t";

    return 0;
}

/*
C++ Code:

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string virus_composition,temp;
    int n,i,j;
    int virus_comp_arr[26] = {0};
    vector<string> blood_composition;
    cin>>virus_composition;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        blood_composition.push_back(temp);
    }
    for(i=0;virus_composition[i]!='\0';i++)
          virus_comp_arr[virus_composition[i]-97] = 1;
    for(i=0;i<n;i++)
    {
                int flag = 0;
                for(j=0;blood_composition[i][j]!='\0';j++)
                {
                    if(virus_comp_arr[blood_composition[i][j]-97] == 0)
                    {
                          printf("NEGATIVE\n");
                          flag = 1;
                          break;
                    }
                }
                if(flag==0)
                    printf("POSITIVE\n");
    }
    return 0;
}


Java Code:
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;
public class Code
{
    public static void main(String[] args)
    {
        String virus_composition;
        int n,i,j;
        Boolean[] virus_comp_arr = new Boolean[26];
        Arrays.fill(virus_comp_arr,Boolean.FALSE);
        ArrayList<String> blood_composition = new ArrayList<String>();
        Scanner in = new Scanner(System.in);
        virus_composition = in.next();
        n = in.nextInt();
        for(i=0;i<n;i++)
        {
            blood_composition.add(in.next());
        }
        for(i=0;i<virus_composition.length();i++)
              virus_comp_arr[virus_composition.charAt(i)-97] = Boolean.TRUE;
        for(i=0;i<n;i++)
        {
                    int flag = 0;
                    for(j=0;j<blood_composition.get(i).length();j++)
                    {
                        if(virus_comp_arr[blood_composition.get(i).charAt(j)-97] == Boolean.FALSE)
                        {
                              System.out.println("NEGATIVE");
                              flag = 1;
                              break;
                        }
                    }
                    if(flag==0)
                        System.out.println("POSITIVE");
        }
    }
}


Python Code:

virus_composition = input()
n = int(input())
blood_composition = []
for i in range(0,n):
    blood_composition.append(input())

#print(virus_composition)
#print(blood_composition)

bool_list = [False]*26

for ch in virus_composition:
    bool_list[ord(ch)-97] = True

'''for i in range(0,26):
    print(chr(i+97)," - ",bool_list[i])'''

for str in blood_composition:
    flag = 0
    for char in str:
        if(bool_list[ord(char)-97] == False):
            print("NEGATIVE")
            flag = 1
            break
    if(flag==0):
        print("POSITIVE")
*/