
#include<iostream>
#include<climits> // <-- Add this for INT_MAX and INT_MIN
using namespace std;
void maxmin(int*, int);
int indx(int*, int);
void rev(int*, int);
void dis(int*, int);//function prototype of only dis was required because we called in rev 
// dis before defining it


// to find maximum minimum element
void maxmin(int*a,int n){
    int s=INT_MAX;
    int l=INT_MIN;
    for(int i=0;i<n;i++){
        if(s>a[i])s=a[i];
        if(l<a[i])l=a[i];
    }
    cout<<"smallest number : "<<s<<"\nlargest number : "<<l;
}
// to find index of target if present
int indx(int*a,int n){
   int t;
    cout<<"\nenter target number : ";
    cin>>t;
     for(int i=0;i<n;i++){
        if(t==a[i]) return i;
    } 
    return -1;
}
//to reverse element
void rev(int*a,int n){
    for(int s=0,e=n-1;s<e;s++,e--){
        //int t=a[s];
        //a[s]=a[e];
        //a[e]=t;
        swap(a[s],a[e]);
    }
    cout<<"array after reversal\n";
     dis(a,n); 
}
//display array
void dis(int*a,int n){
    cout<<"Array is : ";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
// main function
int main(){
    int n;
    cout<<"enter size of array : ";
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cout<<"enter "<<i+1<<" element : ";
        cin>>a[i];
    }
    cout<<"\n";
    maxmin(a,n); 
    cout<<"index="<<indx(a,n)<<endl;
    dis(a,n);
    rev(a,n);   
    delete[] a; // ✅ free memory
    return 0;
}
