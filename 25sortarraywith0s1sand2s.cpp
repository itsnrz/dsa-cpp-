// sort arrays with os,1s and 2s

    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    // library function although it is asked to solve qn without it
    // time complexcity O(nlogn)
    //space complexcity O(1)
    vector<int> sortColorslib(vector<int> nums) {
     sort(nums.begin(),nums.end());
     return nums;
    }
    

    // storing count 
    //time complexcity O(n)
    //number of passes 2
    vector<int> sortColorscount(vector<int>nums){
        int z=0,o=0,t=0;
        for(int val:nums){
            if(val==0)z++;
            else if(val==1)o++;
            else t++;
        }
        int indx=0;
        for(int i=0;i<z;i++)nums[indx++]=0;
        for(int i=0;i<o;i++)nums[indx++]=1;
        for(int i=0;i<t;i++)nums[indx++]=2;
        return nums;
    }

    //dutch national flag algorithm

    /*🧠 Intuition:
    The idea is to use three pointers:

        low: to place the next 0

        mid: the current element under inspection

        high: to place the next 2

    You iterate through the array and swap elements based on their value:

        If nums[mid] == 0: Swap with low, and increment both low and mid
    
        If nums[mid] == 1: Just increment mid
    
        If nums[mid] == 2: Swap with high, and decrement high (don’t increment mid because the new nums[mid] could still be 0, 1, or 2)*/

        //time complexcity O(n)
        //number of passes 1

    vector<int> sortColorsdutch(vector<int>nums){
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){//0s -> 0 t0 low-1
               swap(nums[low],nums[mid]);
               low++;
               mid++;
            }else if(nums[mid]==1){// 1s -> low to mid-1
                mid++;
            }else{// 2s high+1 to size-1
                swap(nums[high],nums[mid]);
                high--;
            }
        }
        return nums;
    }   
int main() {
    vector<int> a = {2,0,2,1,1,0,1,2,0,0};

    cout << "original array : ";
    for (int val : a) cout << val << " ";

    // Library sort
    cout << "\n\n# Using library sort:";
    vector<int> b = sortColorslib(a);
    cout << "\nresult: ";
    for (int val : b) cout << val << " ";
    cout << "\noriginal : ";
    for (int val : a) cout << val << " ";

    // Count sort
    cout << "\n\n# Using counting sort:";
    vector<int> c = sortColorscount(a);
    cout << "\nresult: ";
    for (int val : c) cout << val << " ";
    cout << "\noriginal : ";
    for (int val : a) cout << val << " ";

    // Dutch National Flag
    cout << "\n\n# Using Dutch National Flag algorithm:";
    vector<int> d = sortColorsdutch(a);
    cout << "\nresult: ";
    for (int val : d) cout << val << " ";
    cout << "\noriginal : ";
    for (int val : a) cout << val << " ";

    return 0;
}
