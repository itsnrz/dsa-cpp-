#include<iostream>
using namespace std;
/*int main(){
    int age;
    cout << "please enter your age : ";
    cin >> age;
    if(18>age) cout << "you cant vote , your age : " << age;
    else cout<< "you can vote , your age : " << age;
    return 0;
}*/

/*
int main(){
    int m;
    cout <<"please enter your marks : ";
    cin >> m;
    if(m>=90)cout << "Grade A";
    else if(m<90&&m>=80) cout << "Grade B";
    else cout << "Grade C";
    return 0;
}
*/

/*
int main(){
    char c;
    cout << "enter character : ";
    cin >> c;
    if(c>='a'&&c<='z')cout << "Lower case";// can be done by comparing with ascii value
    else if(c>='A'&&c<='Z')cout << "Upper case";//c>=65&&c<=90 implicit compaarison dne by compiler
    else cout << "not a alphabet ";// c is converted to ascii value
}
*/


/*
//ternary statement
int main(){
    int n;
    cout<< "please enter a number : ";
    cin >> n;
    //(n>0)?cout <<"positive":cout<<"negative";
    cout << (n>0?"positive":"negative");
    return 0;
}
*/


// while loop
/*
int main(){
    int n;
    cout << "enter a number up to where you want to print digits : ";
    cin >> n;
    int i=1;
    while(i<=n){
        cout <<i<<" ";
        i++;
    }
    return 0;
}
*/

// *** use camelCase to wrie name of varuiable = num , bigNum , sum , totalSum

// for loop with break statement
/*
int main(){
    int num;
    cout << "plz enter number upto which you want to sum : ";
    cin >> num;
    int sum=0;
    for(int i=1;i<=num;i++){
        //cout<<i<<" ";
        sum+=i;
        if(i==3)break;
    }
    cout<< "sum of digits from 1 to "<<num<<" is : "<<sum;
    return 0;
}
*/

// sum od odd numbers upto num;
/*
int main(){
    int num,sum=0;
    cout<<"enter a number : ";
    cin >> num;
    for(int i=1;i<=num;i++)
    if(i%2!=0)sum+=i;
    cout<<"sum of all odd number between 1 and "<<num<<" is : "<<sum;
    return 0;
}
*/


//do while loop
/*
int main()
{
    int num;
    cout<<"enter a num : ";
    cin >> num;
    do{
        cout <<"entered "<< num<<" is greater than 9999";
    }while(num>9999);
    return 0;
}
*/

// Program to check if an entered number is prime
/*
int main() {
    int num, flag = 0;
    
    // Input from user
    cout << "Enter a number: ";
    cin >> num;
    
    // Handle numbers less than 2 (not prime by definition)
    if (num < 2) {
        cout << "Number is not prime";
        return 0; // Exit the program early
    }
    
    // Check divisibility up to sqrt(num) without using cmath
    for (int i = 2; i * i <= num; i++) {//instead of i*i<=num you can use i*i<num+1
    if (num % i == 0) {
        flag = 1; // Found a divisor → not prime
        break;
    }
}

// Output based on result
if (flag == 0)
cout << "Entered number " << num << " is prime";
else
cout << "Entered number " << num << " is not prime";

return 0;
}
*/


// nested loop star pattern print 
int main(){
    int num;
    cout<<"enter number of star : ";
    cin >> num;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
    return 0;
}