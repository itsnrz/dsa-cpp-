// linear search in a 2d matrix


#include<iostream>
#include<vector>
#include<utility>
using namespace std;
pair<int,int> linear_search(vector<vector<int>>&matrix,int target){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++)
        if(matrix[i][j]==target)return make_pair(i,j);
    }
    return make_pair(-1,-1);
}
int main() {
    int rows, cols, val, target;
    vector<vector<int>> mat;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    // Input matrix
    cout << "Enter matrix values row by row:\n";
    for (int i = 0; i < rows; i++) {
        vector<int> row;
        for (int j = 0; j < cols; j++) {
            cin >> val;
            row.push_back(val);
        }
        mat.push_back(row);
    }

    // Input target
    cout << "Enter target value to search: ";
    cin >> target;

    // Find target
    pair<int, int> pos = linear_search(mat, target);

    // Output result
    if (pos.first != -1)
        cout << "Target found at position: (" << pos.first << ", " << pos.second << ")" << endl;
    else
        cout << "Target not found in matrix." << endl;

    return 0;
}
