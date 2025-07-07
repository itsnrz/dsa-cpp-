/*
#include<iostream>
#include<vector>
using namespace std;
int area(vector<int>n){
    int maxa=0,ca=0,s=n.size();
    for(int i=0;i<s;i++){
        ca=0;
        for(int j=i+1;j<s;j++){
            int h=min(n[i],n[j]);
            int w=j-i;
            ca=h*w;
            maxa=max(maxa,ca);
        }
    }
    return maxa;
}
int main(){
    vector<int>v;
    int n,val;
    cout<<"enter number of heightsc : ";
    cin>>n;
    cout<<"enter heights : ";
    for(int i=0;i<n;i++){
        cin>>val;
        v.push_back(val);
    }
    int maxa=area(v);
    cout<<"maximum area  container has area = "<<maxa<<endl;
    return 0;
}
*/

#include<iostream>
#include<vector>
using namespace std;

//                    BRUTE FORCE   O(N^2)
/*
// Function to calculate the maximum area between two lines
int area(vector<int> n) {
    int maxa = 0, ca = 0;
    int s = n.size();
    
    // Brute force: check all possible pairs of lines
    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
            int h = min(n[i], n[j]); // height is limited by the shorter line
            int w = j - i;           // width between the lines
            ca = h * w;              // area = height * width
            maxa = max(maxa, ca);    // update maximum if needed
        }
    }
    
    return maxa;
}

int main() {
    vector<int> v;
    int n, val;
    
    cout << "Enter number of heights: ";
    cin >> n;
    
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
    }
    
    int maxa = area(v);
    cout << "Maximum area container can hold is: " << maxa << endl;
    return 0;
}

*/

// 2 pointer approach  optimal O(n)
int area(vector<int>n){
    int maxa=0,ca=0,s=n.size();
    for(int i=0,e=s-1;i<e;){
        int h=min(n[i],n[e]);
        int w= e-i;  // abs(i-e) is avoided because in all the cases  e will be bigger than i
        ca=h*w;
        maxa=max(maxa,ca);
        if(n[i]<n[e])i++;
        else e--;
    }
    return maxa;
}

int main() {
    vector<int> v;
    int n, val;
    
    cout << "Enter number of heights: ";
    cin >> n;
    
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
    }
    
    int maxa = area(v);
    cout << "Maximum area container can hold is: " << maxa << endl;
    return 0;
}
