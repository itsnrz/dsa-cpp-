/*Allocate Minimum Pages
Difficulty: Medium Accuracy: 35.51% Submissions: 290K+ Points: 4 Average Time: 35m

You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

    Each student receives atleast one book.
    Each student is assigned a contiguous sequence of books.
    No book is assigned to more than one student.

The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.

Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation can not be done.

Input: arr[] = [22, 23, 67], k = 1
Output: 112

Constraints:
1 <=  arr.size() <= 106
1 <= arr[i] <= 103
1 <= k <= 103 
Expected Complexities
Company Tags
InfosysAmazonMicrosoftGoogleCodenationUber
Topic Tags
SearchingDivide and ConquerAlgorithms
Related Interview Experiences
Amazon Interview Experience On Campus For Sde 1 5
Related Articles
Allocate Minimum Number Pages*/

#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int> &arr,int n,int m,int maxallowed){//O(n)
      int stu=1,pages=0;
      for(int i=0;i<n;i++){
        if(arr[i]>maxallowed)return false;
        if((pages+arr[i])<=maxallowed)pages+=arr[i];
        else{
            stu++;
            pages=arr[i];
        }
      }
      return stu>m? false : true;
}
int allocateBooks(vector<int> &arr,int n,int m){//O(logN * n)   here n is number of books or size of books    m is number of student
    if(m>n)return -1;// there is not enough book for each student
    int sum=0,mid=0,ans=-1;
    for(int i=0;i<n;i++)sum+=arr[i];//O(n)
    int s=0,e=sum;//range of possible ans
    while(s<=e){// O(logN*n)
        mid=s+(e-s)/2;
        if(isValid(arr,n,m,mid)){//if current mid is valid
           ans=mid;// store it as ans and move to left side of range to find ans minimum then current
           e=mid-1;
        }else{//mid is not valid move to right side of range
           s=mid+1;
        }
    }
    return ans;
}
int main(){
  vector<int> arr={2,1,3,4};
  int n=4,m=2;// n is size of array of book, m is number of student
  cout<<allocateBooks(arr, n, m)<<endl;
  return 0;
}

  