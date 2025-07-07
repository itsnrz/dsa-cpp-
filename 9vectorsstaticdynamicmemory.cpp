#include<iostream>
#include<vector>
using namespace std;
// capacity: it gives capacity as when we push new element new vector is form of name same as previous and size double of previous in memory previous vector is deleted
/*
int main(){
    vector<int>vec;
    cout<<"size is: "<<vec.size()<<endl;
    vec.push_back(25);
    vec.push_back(15);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    cout<<"size of vector after pushing  : "<<vec.size()<<endl;
    cout<<"capacity : "<<vec.capacity();
    return 0;
}
*/
int target(vector<int>&n,int t){
    int index=0;
    for(int val:n){
        if(val==t)return index;
        index++;
    }
    return -1;
}
void rev(vector<int>&n){
    int e=n.size()-1;
    int s=0;
    for(;s<e;s++,e--){
       swap(n[s],n[e]);
    }
}
int main(){
    vector<int>vec={1,2,3};
    cout<<"elements of vector are : ";
    for(int val:vec) cout<<val<<" ";
    cout<<endl;
    int t;
    cout<<"enter target value : ";
    cin>>t;
    int indx=target(vec,t);
    if(indx!=-1)cout<<"index of target in vector is: "<<indx<<endl;
    else cout<<"target not found"<<endl;
    rev(vec);
    cout<<"elements of vector after reversing it : ";
    for(int val:vec) cout<<val<<" ";
    cout<<endl;
    return 0;
}
