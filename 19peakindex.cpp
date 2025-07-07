    //                    peak index mountain array
#include<iostream>
#include<vector>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {
       for(int i=1;i<arr.size();i++)
       if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])return i;
       return -1;
    }
int peakIndexInMountainArrabin(vector<int>& arr){
        int s=+1,e=arr.size()-2,mid=0;// not including first and last element as they can never be peak index
        while(s<=e){
            mid=s+(e-s)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1])return mid;
            else{
                if(arr[mid]<arr[mid-1])e=mid-1;
                else s=mid+1;
            }
        }
        return -1;
    }
    int main() {
    // First test array and target
    vector<int> a1 = {4,5,6,7,0,1,2};
    int t1 =0;
    cout << "peak index of array (brutte force approach)(O(N)): " <<peakIndexInMountainArray(a1) << endl;
    cout << "peak index of array (binary search approach)(O(NlogN)): " <<peakIndexInMountainArrabin(a1) << endl;
    return 0;
}