// 204. Count Primes (LeetCode)
/* The Sieve of Eratosthenes is an efficient algorithm to 
   find all prime numbers up to a given number n. 
   It works by iteratively marking the multiples of each prime number 
   starting from 2. */

#include<iostream>
#include<vector>
using namespace std;

// Sieve of Eratosthenes: Optimal approach for finding number of prime numbers in given range
int count_prime(vector<int>& a){
    int n = a.size(), count = 0;
    vector<bool> b(n, true); // create a boolean vector of size n, initialized to true
    b[0] = b[1] = false;     // 0 and 1 are not prime numbers

    for(int i = 2; i < n; i++){
        if(b[i]){
            count++;         // increment count as it's a prime
            for(int j = i * 2; j < n; j += i)
                b[j] = false; // mark all multiples of i as not prime
        }
    }
    return count;
}

int main(){
    int n, val;
    vector<int> s;
    cout << "plz enter size of vector : ";
    cin >> n;
    cout << "enter numbers : ";
    for(int i = 0; i < n; i++){
        cin >> val;
        s.push_back(val);
    }
    cout << "number of prime number present in vector are : " << count_prime(s) << endl;
    return 0;
}
