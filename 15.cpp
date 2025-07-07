#include<iostream>
#include<vector>
using namespace std;

/* ❌ Brute-force Approach – Time Complexity: O(N^2)
   This will give TLE for large inputs */
 /*
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> a;
    int mul = 1, s = nums.size();
    for (int i = 0; i < s; i++) {
        mul = 1;
        for (int j = 0; j < s; j++) {
            if (i != j) mul *= nums[j];
        }
        a.push_back(mul);
    }
    return a;
}
*/

/* ❌ Full product / Division Approach – Wrong for zeros
   Fails if any element is zero (division by zero or incorrect value) */
/*
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> a;
    int mul = 1, s = nums.size();
    for (int i = 0; i < s; i++) {
        mul *= nums[i];
    }
    for (int i = 0; i < s; i++) {
        a.push_back(mul / nums[i]); // Incorrect when nums[i] == 0
    }
    return a;
}
*/

/* ✅ Prefix-Suffix Approach (Space: O(N), Time: O(N), Runtime ~ 8ms) */
/*
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> a(n, 1);     // Output vector initialized to 1
    vector<int> p(n, 1);     // Prefix product
    vector<int> s(n, 1);     // Suffix product

    // Calculate prefix product for each index
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] * nums[i - 1];
    }

    // Calculate suffix product for each index
    for (int i = n - 2; i >= 0; i--) {
        s[i] = s[i + 1] * nums[i + 1];
    }

    // Multiply prefix and suffix products
    for (int i = 0; i < n; i++) {
        a[i] = p[i] * s[i];
    }

    return a;
}
*/

/* ✅ Optimized Prefix-Suffix Approach (Space: O(1), Time: O(N), Runtime ~ 0ms) */
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> a(n, 1);  // Output vector initialized to 1

    // Step 1: Prefix product – stored directly in result vector 'a'
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] * nums[i - 1];
    }

    // Step 2: Suffix product – multiply directly into 'a'
    int s = 1;  // Running suffix product
    for (int i = n - 2; i >= 0; i--) {
        s *= nums[i + 1];   // Update suffix product
        a[i] *= s;          // Multiply prefix (already stored) by suffix
    }

    return a;
}

int main() {
    vector<int> v;
    int n, val;
    
    cout << "Enter size : ";
    cin >> n;
    
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
    }

    vector<int> result = productExceptSelf(v);

    cout << "Product of array elements except self:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

