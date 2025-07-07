//443. String Compression
#include <iostream>
#include <string>
#include<vector>
using namespace std;
int compress(vector<char>& chars) {
        int n=chars.size();
        int indx=0;//to store indx of result
        for(int i=0;i<n;){
            char ch=chars[i];
            int count=0;
            while(i<n&&ch==chars[i]){// if current char is equall to next increment count
                count++;
                i++;
            }
            if(count==1)chars[indx++]=ch;//if count ==1 store character only 
            else{// if count is more than one store frequency also
                chars[indx++]=ch;
                string digits=to_string(count);// this function converts number to string
                for(char c:digits)chars[indx++]=c;// store each digit
            }
        }
        chars.resize(indx);// resize chars 
        return indx;//return its size which is equall to indx
    }
int main(){
    vector<char>c;
    int n;
    char ch;
    cout<<"enter size of string : ";
    cin>>n;
    cout<<"enter string : ";
    for(int i=0;i<n;i++){
        cin>>ch;
        c.push_back(ch);   
    }
    compress(c);
    cout<<"compressed vector is : ";
    for(char x:c)cout<<"'"<<x<<"'";
    return 0;
}