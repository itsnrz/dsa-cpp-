#include<iostream>
#include<limits.h>
using namespace std;

//code to print all subarrays
/*
int main(){
    int n=5;
    int a[n]={1,2,3,4,5};
    for(int st=0;st<n;st++){
        for(int end=st;end<n;end++){
            for(int i=st;i<=end;i++)cout<<a[i];
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/

// maximum subarray sum code
/*
int main(){
    int n=5;
    int a[n]={1,2,3,4,5};
    int max_sum=0;
    for(int st=0;st<n;st++){
        int sum=0;
        for(int end=st;end<n;end++){
            sum+=a[end];
            max_sum=max(sum,max_sum);
        }
    }
    cout<<"maximum sub array sum is : "<<max_sum<<endl;
    return 0;
}
*/


//kadanes algorithm
/*
int main(){
    int n=5;
    int a[n]={-1,-2,-3,-4,-5};
    int current=a[0],absmax=a[0];
    for(int i=1;i<n;i++){
        current+=a[i];
        absmax=max(current,absmax);
        if(current<0) current =0;
    }
    cout<<"maximum sub array sum is : "<<absmax<<endl;
    return 0;
}
*/
int main(){
    int n=5;
    int a[n]={-1,-2,-3,-4,-5};
    int current=0,absmax=INT_MIN;
    for(int i=0;i<n;i++){
        current+=a[i];
        absmax=max(current,absmax);
        if(current<0) current =0;
    }
    cout<<"maximum sub array sum is : "<<absmax<<endl;
    return 0;
}


