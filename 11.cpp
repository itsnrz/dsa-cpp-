     // PAIR SUM QN

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
vector<int> find(vector<int>n,int t,vector<int>&a){
    int st=0,e=n.size()-1;
    while(st<e){
        if(n[st]+n[e]==t){
           a.push_back(st);
           a.push_back(e);
           return a;
        }
        else if(n[st]+n[e]>t)e--;
        else st++;
    }
    return a;
}
int main(){
    int t;
    vector<int>vec={1,2,3,4,5,6,7};
    cout<<"enter target : ";
    cin>>t;
    vector<int>ans;
    find(vec, t,ans);
    cout<<"indexes are : "<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}


// majority element


// 1 BRUTE FORCE  runtime:- 2427ms, beats:- 5.02%  O(n^2)
/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int val:nums){
            int freq=0;
            for(int c :nums)if(c==val)freq++;
            if(freq>n/2)return val;
        }
        return -1;
    }
};*/




// optimized sorting approach Runtime:- 3ms , Beats:- 29.17% )  O(nlogn)
   /*
   int majorityElement(vector<int>& nums) {
    int s=nums.size();
    sort(nums.begin(),nums.end());
    int f=1,n=nums[0];
    for(int i=1;i<s;i++){
        if(nums[i]==n)f++;
        else {
            n=nums[i];
            f=1;
        }
        if(f>s/2)return n;
    }
     return n;
   }
   */



    
 // moore's algorithm  Runtime:- 0ms , Beats:- 100.00%  O(n)

 int majorityElement(vector<int>& nums) {
    int s=nums.size();
    int f=0,ans=0;
    for(int i=0;i<s;i++){
        if(f==0) ans=nums[i];
        if(ans==nums[i])f++;
        else f--;
    }
    int c=0;
    for(int val:nums)if(val==ans)c++;
    if(c>s/2) return ans;
    return -1;
 }
