#include<iostream>
#include<vector>
using namespace std;

//      VECTOR    INITIALIZATION


// 1st way
/*int main(){
    vector<int> vec;//size of vector is 0 over here 
    cout<<vec[0]<<endl;// this will throw segmentation fault because there is nothing in vector
    return 0;
}*/

// 2nd way
/*int main(){
    vector<int> vec={1,2,3};//size 3
    cout<<vec[0]<<endl;//g++ -std=c++11 9vectors.cpp -o 9vectors && ./9vectors
    //The -std=c++11 flag  is used to
    // enable C++11 features when compiling with g++. Whether you need
    // it depends on:
}*/

//3rd way
/*
int main(){
    vector<int> vec(3,0);// value stored at every index from 0 t0 2 will be 0
    cout<<vec[0]<<endl;
    cout<<vec[1]<<endl;
    cout<<vec[2]<<endl;
    return 0;
}
*/


//           FOR VECTORS WE HAVE  =  FOR EACH LOOP

// 1st int example
/*
int main(){
    vector<int> vec(3,0); //the type of vector must be same ti initialized variable in for
    for(int val:vec){
        cout<<val<<endl;
    }
    return 0;
}
*/

// 2nd char example
/*
int main(){
    vector<char> vec={'z','a','g'}; //the type of vector must be same ti initialized variable in for
    for(char val:vec){
        cout<<val<<endl;
    }
    return 0;
}
*/


//                         VECTOR         FUNCTIONS

// 1st fuction size : gives size of vector
/*
int main(){
    vector<char> vec={'z','a','g'};
    cout<<"size is: "<<vec.size()<<endl;
    for(char val:vec){
        cout<<val<<endl;
    }
    return 0;
}
*/

//2nd function push_back : is use to push an element at last of vector
/*
int main(){
    vector<int>vec;
    cout<<"size is: "<<vec.size()<<endl;
    vec.push_back(25);
    vec.push_back(15);
    vec.push_back(5);
    cout<<"size of vector after pushing  : "<<vec.size()<<endl;
    for(int val:vec){
        cout<<val<<endl;
    }
    return 0;
}
*/

//3rd function pop_back : use to delete last element
/*
int main(){
    vector<int>vec;
    cout<<"size is: "<<vec.size()<<endl;
    vec.push_back(25);
    vec.push_back(15);
    vec.push_back(5);
    cout<<"size of vector after pushing  : "<<vec.size()<<endl;
    for(int val:vec){
        cout<<val<<endl;
    }
    vec.pop_back();
    cout<<"size of vector after removing/poping last element : "<<vec.size()<<endl;  
    for(int val:vec){
        cout<<val<<endl;
    }
    return 0;
}
*/

// 4th function front: use to print front value
/*
int main(){
    vector<int>vec;
    cout<<"size is: "<<vec.size()<<endl;
    vec.push_back(25);
    vec.push_back(15);
    vec.push_back(5);
    cout<<"size of vector after pushing  : "<<vec.size()<<endl;
    cout<<"front value : "<<vec.front();
    return 0;
}
*/


// 5th function back : use to print back value
/*
int main(){
    vector<int>vec;
    cout<<"size is: "<<vec.size()<<endl;
    vec.push_back(25);
    vec.push_back(15);
    vec.push_back(5);
    cout<<"size of vector after pushing  : "<<vec.size()<<endl;
    cout<<"back value : "<<vec.back();
    return 0;
}
*/

//6th function at : use to print index at a value
/*
int main(){
    vector<int>vec;
    cout<<"size is: "<<vec.size()<<endl;
    vec.push_back(25);
    vec.push_back(15);
    vec.push_back(5);
    cout<<"size of vector after pushing  : "<<vec.size()<<endl;
    cout<<"value at 1 : "<<vec.at(1);
    return 0;
}
*/



 // code to take input from user during run time
int main() {
    int n, val;
    vector<int> vec;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        vec.push_back(val);  // Add value to the vector
    }

    // Display the vector
    cout << "You entered: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}