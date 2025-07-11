// LeetCode 54: Spiral Matrix
/*
Intuition:
We are given a matrix and we need to traverse it in spiral order:
→ top row → right column ↓ → bottom row ← → left column ↑
We continue shrinking the boundaries until all elements are covered.

Approach:
- Use 4 pointers: srow, scol, erow, ecol
- Loop while (srow <= erow && scol <= ecol)
- Traverse in 4 directions with edge-case checks to avoid duplication
*/


#include<iostream>
#include<vector>
#include<utility>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>&mat){
    int m=mat.size(),n=mat[0].size();
    int srow=0,scol=0,erow=m-1,ecol=n-1;
    vector<int>ans;// to store ans
    while(srow<=erow&&scol<=ecol){
        //top
        for(int j=scol;j<=ecol;j++){
             ans.push_back(mat[srow][j]);
        }
        //right
        for(int j=srow+1;j<=erow;j++){
             ans.push_back(mat[j][ecol]);
        }
        //bottom
        for(int j=ecol-1;j>=scol;j--){
            if(srow==erow)break;
             ans.push_back(mat[erow][j]);
        }
         //left
        for(int j=erow-1;j>=srow+1;j--){
            if(scol==ecol)break;
             ans.push_back(mat[j][scol]);
        }
        srow++; erow--; scol++; ecol--;  
    }
    return ans;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral order: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}