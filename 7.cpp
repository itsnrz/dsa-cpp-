#include<iostream>
using namespace std;



// BITWISE OPERATOR
/*
int main(){
    int a,b;
    cout<<"enter two numbers : ";
    cin>>a>>b;
    cout<<"a&b : "<<(a&b)<<endl;//bitwise and
    cout<<"a|b : "<<(a|b)<<endl;//bitwise or
    cout<<"a^b : "<<(a^b)<<endl;//bitwise x-or
    cout<<"a<<b : "<<(a<<b)<<endl;//bitwise left shift(a*2^b)
    cout<<"a>>b : "<<(a>>b)<<endl;//bitwise right shift(a/2^b)
    return 0;
}
*/


// size of data types
int main(){
    cout<<"char : "<<sizeof(char)<<endl;//1
    cout<<"int : "<<sizeof(int)<<endl;//4
    cout<<"long int : "<<sizeof(long int)<<endl;//generally 4 or greter than 4
     cout<<"long long int : "<<sizeof(long long int)<<endl;//8
    cout<<"short int : "<<sizeof(short int)<<endl;//2
    cout<<"double : "<<sizeof(double)<<endl;//8
    return 0;
}