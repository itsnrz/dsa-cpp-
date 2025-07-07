#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isValid(vector<int>&c,int k,int maxallow){
    // stalls are sorted 
    int cows=1,pos=c[0];// track position of cow
    for(int i=0;i<c.size();i++){// initialize i from 1 as  first cow is assumed to be placed at zero'th index
        if((c[i]-pos)>=maxallow){// if the distance is greter than maxallowed(mid) 
            cows++;//put next cow
            pos=c[i];// now track its position
        }
        if(cows>=k)return true;// if number of cows become equall to k hence return true
    }
    return false;// loop ends return false
}
int aggressiveCows(vector<int>c,int k){
     int n=c.size()-1;
     sort(c.begin(),c.end());//sorting stall to get minimum and max value to find e
     int st=1,e=c[n-1]-c[0],mid=0,ans=0;//st=1 because minimum distance between two cow is 1 and maximum will be difference of last stall to first stall
     while(st<=e){
        mid=st+(e-st)/2;
        if(isValid(c,k,mid)){//if mid is valid store it as ans
            ans=mid;
            st=mid+1;// move to right to find any bigger value of mid
        }else e=mid-1;// if mid invalid meanss the distance is smaller than mid hence move to left 
     }
     return ans;
}
int main() {
    vector<int> stalls = {1, 2, 4, 8, 9}; 
    int k = 3;
    int ans = aggressiveCows(stalls, k);
    cout << ans;
    return 0;
}