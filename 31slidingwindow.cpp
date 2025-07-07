//567. Permutation in String
#include <iostream>
#include <string>
using namespace std;
    bool checkInclusion(string s1, string s2) {
       int f1[26]={0}; 
       for(int i=0;s1[i];i++)f1[s1[i]-'a']++;//frequency of s1(word)
       int st=0,size=s1.length();// st store start position of window and size store size of window
       while(st+size<=s2.length()){// we are traversing window upto last element of s2
        int match=1;// used to determine if permutation found
        int f2[26]={0};// used to store frequency of window
        for(int i=st;i<size+st;i++)f2[s2[i]-'a']++;
        for(int i=0;i<26;i++){// traversing through frequency
            if(f1[i]!=f2[i]){// if frequency doesnt change match to 0
                match =0;
                break;
            }
        }
        if(match==1)return true;// if match is 1 it means frequencies had matched return true 
        st++;// increment st for next iteration
       }
       return false;// if loop ends no match is found return false
}
int main(){
    string s1,s2;
    cout<<"enter first string : ";
    getline(cin,s1);
    cout<<"enter second string : ";
    getline(cin,s2);
    if(checkInclusion(s1,s2))cout<<"permutation found "<<endl;
    else cout<<"permutation not found "<<endl;
    return 0;
}