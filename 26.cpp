//        merge 2 sorted array
/*class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int indx=m+n-1;// storing value from last place at nums1
       int i=m-1,j=n-1;// i stores index of last element in nums1 which is not 0,j stores the same for nums2 
       while(i>=0&&j>=0){//until both index are greater than 0
        if(nums1[i]>nums2[j]){// if nums1[i] is greater move it to indx
            nums1[indx]=nums1[i];
            i--;// decrement i and indx for next iteration
            indx--;
        }else{
            nums1[indx]=nums2[j];//if nums2[j] is greter store it at indx place in nums1
            indx--;// decrement j and indx for next iteration
            j--;
        }
       }
       while(j>=0){// if i becomes less than 0 and j>=0 we need to store rest element to nums1
        nums1[indx--]=nums2[j--];
       }
    }
};*/



// next permutation
/*steps :
1 = find pivot(a number) from last  to first element do lopping if a[i]>a[i-1] its pivot
2 = swap pivot with right most element 
3 = reverse remaining e;lement and add in places 
*/

/*class Solution {
public:
    // library function
    //void nextPermutation(vector<int>& nums){
    //    next_permutation(nums.begin(),nums.end());
    //}
    
     void nextPermutation(vector<int>& nums) {
         int l=nums.size()-1,pivot=-1;
         //1st step looping from last to first element
         for(int i=l-1;i>=0;i--){//  find pivot
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;// as soon as pivot ifs found break loop
            }
         }
         // 2nd step if no bigger number can be formed than make the smaller (pivot=-1)
         if(pivot==-1){// reverse it according to qn
            //int s=0,e=l;
            //while(s<e){
            //    int t=nums[s];
            //    nums[s]=nums[e];
            //    nums[e]=t;
            //    s++;
            //    e--;
            //}
            reverse(nums.begin(),nums.end());
            return;
         }
         // 3rd step find right most element bigger than pivot and swap there places
        for(int i=l;i>pivot;i--){// right most element
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        // 4th step reverse element from pivot +1 to end
       //for(int i=pivot+1,j=l;i<j;i++,j--){// reversinfg digit betwwn pivot and right most  to create smallest number
       //    int t=nums[i];
       //    nums[i]=nums[j];
       //    nums[j]=t;
       //}
       reverse(nums.begin()+pivot+1,nums.end());
    }
};*/
