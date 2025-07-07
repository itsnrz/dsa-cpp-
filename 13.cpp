//       COMPUTE X^N(binary exponentiation)       


    #include<iostream>
    #include<vector>
    using namespace std;
    double myPow(double x, int n) {
        long bn = n;      // Convert to long to handle overflow (e.g., INT_MIN)
        double ans = 1.0; // Initialize result to 1 (neutral for multiplication)

        // Handle all simple and special cases
        if (n == 0) return 1.0;       // Any number raised to power 0 is 1
        if (n == 1) return x;         // Power 1, return base itself
        if (x == 1) return 1.0;       // 1 to any power is 1
        if (x == 0) return 0.0;       // 0 to any positive power is 0
        if (x == -1 && n % 2 == 0) return 1.0;  // (-1)^even = 1
        if (x == -1 && n % 2 != 0) return -1.0; // (-1)^odd = -1

        // Handle negative exponent case
        if (n < 0) {
            x = 1 / x;     // Invert x for negative power
            bn = -bn;      // Make exponent positive
        }

        // Binary Exponentiation Loop (O(log n) time)
        while (bn > 0) {
            // If current exponent is odd, multiply the result
            if (bn % 2 == 1) {
                ans *= x;
            }

            // Square the base for next power
            x *= x;

            // Divide exponent by 2
            bn /= 2;
        }

        // Return the final result after loop
        return ans;
    }
    int main(){
        int x,n;
        cout<<"enter num and its power : ";
        cin>>x>>n;
        double res= myPow(x,n) ;
        cout<<"x raise to power n is "<<res<<endl;
    }




//              STOCK   BUY AND SELL
 // assume every day as selling day except for 1st as we cant sell in first day
 // assume day 1 to be bestbuy for every day check if we can make profit
 // profit is made when price of ith day is more than bestbuy 
 // we also have to ensure that this profit is also bigger than previous maxp
 // if true put the profit in maxp
 // if best buy is bigger than price at ith day it means 
 // we can make more money if we had bought stock at ith day so change bestbuy to   price at ith day
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int maxp=0,bestbuy=prices[0],e=prices.size();
     for(int i=1;i<e;i++){
        if(bestbuy<prices[i])maxp=max(maxp,prices[i]-bestbuy);
        else bestbuy=prices[i];
     }  
     return maxp;
    }
};