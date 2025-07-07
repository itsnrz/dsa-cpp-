#include<iostream>
using namespace std;

// decimal to binary
/*
int binary(int n){
    int pow=1,b=0,rem=0;
    while(n>0){
        rem=n%2;
        n/=2;
        b+=rem*pow;
        pow*=10;
    }
    return b;
}
int main(){
    int n;
    cout<<"enter a number(decimal) you want to convert to binary : ";
    cin>>n;
    cout<<"binary conversion of "<<n<<" is : "<<binary(n);
    return 0;
}
*/


// binary to decimal conversion
/*
int decimal(int n){
    int pow=1,rem=0,res=0;
    while(n>0){
        rem=n%10;
        res+=rem*pow;
        pow*=2;
        n/=10;
    }
    return res;
}
int main(){
    int n;
    cout<<"enter a number(binary) you want to convert to decimal : ";
    cin>>n;
    cout<<"decimal conversion of "<<n<<" is : "<<decimal(n);
    return 0;
}
*/
 