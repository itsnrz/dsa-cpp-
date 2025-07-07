#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicatexor(vector<int>& nums) { //using xor
        int r=0;
        for(int val:nums)r^=val;
        return r;
}
int singleNonDuplicatelinear(vector<int>& nums) {// using linear search
    int s = nums.size();
    if (s == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[s - 1] != nums[s - 2]) return nums[s - 1];
    for (int i = 1; i < s - 1; i++) {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) return nums[i];
    }
    return -1;
}
int singleNonDuplicatebin(vector<int>& nums){ //binary search  O(logN)
    int s=0, e=nums.size()-1,mid=0;
    if(e==0) return nums[0];//e will be zero if size of num is 1 which means single element present hence return it only.
    while(s<=e) {
        mid=s+(e-s)/2;
        // Edge elements check
        if (mid==0&&nums[0]!=nums[1]) return nums[0];// if mid==0 , there is no previous element and if next element is different nums[mid] is ans.
        if (mid==e&&nums[e]!=nums[e-1]) return nums[e];// if mid==e , mid is equall to last element so check its previous one if it is different ans is nums[mid].
        // Unique element found
        if (nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]) return nums[mid];// if mid not equall to previous and next it is the ans.

        // Binary search logic based on pair index
        if (mid%2==0) {//mid of even length
            if (nums[mid-1]==nums[mid]) e=mid-1;// if element previous to mid is same as mid ,remaning element count is odd so shrunk search space to left.
            else s=mid+1;// else shrunk search space to right.
        } else {// mid of odd length
            if (nums[mid-1]==nums[mid]) s=mid+1;//if mid is equall to previous,remaning element count is even,shrunk search space to right.
            else e=mid-1;//else shrunk search space to left.
        }
    }
    return -1;
}    
int main() {
    // First test array and target
    vector<int> a1 = {1,1,2,3,3,4,4,8,8};
    int t1 =0;
    cout << "single element (xor approach)(O(N)): " <<singleNonDuplicatexor(a1) << endl;
    cout << "single element (linear search approach)(O(N)): " <<singleNonDuplicatelinear(a1) << endl;
    cout << "single element (binary search approach)(O(NlogN)): " <<singleNonDuplicatebin(a1) << endl;
    return 0;
}