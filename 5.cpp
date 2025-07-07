#include<iostream>
using namespace std;

// sum of 2 num
/*
double sum(double a,double b){// formal parameter
double SUM=a+b;
return SUM;
}
int main(){
    int a,b;
    cout<<"enter two numbers : ";
    cin>>a>>b;
    //int s=sum(a,b);
    cout<<"sum of "<<a<<" and "<<b<<" is : "<<sum(a,b);//actual parameter ?argument
    return 0;
}
*/

//sum upto n from 1
/*
int sum(int n){
    int s=0;
    for(int i=1;i<=n;i++)s+=i;
    return s;
}
int main(){
    int n;
    cout<<"plz enter a num : ";
    cin >>n;
    cout<<"sum of number from 1 to "<<n<<" is : "<<sum(n);
    return 0;
}
*/



//n factorial
/*
double fact(int n){
    if(n==0||n==1)return 1;
    else return n*fact(n-1);
}
int main(){
    int n;
    cout<<"enter a num : ";
    cin>>n;
    cout<<"factorial of "<<n<<" is : "<<fact(n);
    return 0;
}
*/

// sum of digit
/*
int sum(int n){
    int s=0;
    while(n>0){
        s=s+n%10;
        n/=10;
    }
    return s;
}
int main(){
    int n;
    cout<<"enter a num : ";
    cin>>n;
    cout<<"sum of digit of "<<n<<" is : "<<sum(n);
    return 0;
}
*/


//binomial coefficient(nCr) for n & r
/*
double fact(int n){
    if(n==0||n==1)return 1;
    else return n*fact(n-1);
}
int main(){
    int n,r;
    // Input loop using while instead of goto
    while (1) {
        cout << "Enter n and r: ";
        cin >> n >> r;
        
        if (n >= r) break; // Valid input → exit loop
        
        cout << "*** n must be bigger than or equal to r ***\n";
    }
    double a,b,c;
    a=fact(n);
    b=fact(r);
    c=fact(n-r);
    double NCR=a/(b*c);
    cout<<"\nnCr is : "<<NCR;
    return 0;
}
*/ 


// iterative approach to generate the Fibonacci series.
/*
void fib(int n){
    int  a=0,b=1,c=0;
    for(int i=0;i<n;i++){
        if(i==0)cout<<"0 ";
        else if(i==1)cout<<"1 ";
        else{
            c=a+b;
            a=b;
            b=c;
            cout<<c<<" ";
        }
    }
}
int main(){
    int n;
    cout<<"enter a num : ";
    cin>>n;
    fib(n);
    return 0;
}
*/




// Recursive function to return the nth Fibonacci number
int fib(int n) {
    if (n == 0) return 0;        // Base case 1
    else if (n == 1) return 1;   // Base case 2
    else return fib(n - 1) + fib(n - 2); // Recursive case
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci series (recursive): ";
    for (int i = 0; i < n; i++) {
        cout << fib(i) << " ";
    }

    return 0;
}
