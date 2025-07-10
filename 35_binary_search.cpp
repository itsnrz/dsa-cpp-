#include <iostream>
#include <vector>
using namespace std;

// 1 way :-  Row-wise Binary Search      Time Complexity = O(m × log n)
bool rowWiseBinarySearch(vector<vector<int>>& matrix, int target) {
    int row_size = matrix.size();
    for (int i = 0; i < row_size; i++) {
        int column_size = matrix[i].size();
        int start = 0, end = column_size - 1;
        if (target >= matrix[i][start] && target <= matrix[i][end]) {
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] > target) end = mid - 1;
                else start = mid + 1;
            }
        }
    }
    return false;
}


// 2 way :- Two level binaery search      Time Complexity = O(log m + log n)
// Helper for searching element in founded row
bool binarySearchRow(vector<vector<int>>& matrix, int target, int row, int colSize) {
    int start = 0, end = colSize - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (matrix[row][mid] == target) return true;
        else if (matrix[row][mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return false;
}
         
bool twoLevelBinarySearch(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int start_row = 0, end_row = m - 1;
    while (start_row <= end_row) {
        int mid_row = start_row + (end_row - start_row) / 2;
        if (target >= matrix[mid_row][0] && target <= matrix[mid_row][n - 1])
            return binarySearchRow(matrix, target, mid_row, n);
        else if (target > matrix[mid_row][n - 1])
            start_row = mid_row + 1;
        else
            end_row = mid_row - 1;
    }
    return false;
}

// Main function
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target = 3;

    cout << "Using Row-wise Binary Search: ";
    cout << (rowWiseBinarySearch(matrix, target) ? "Found" : "Not Found") << endl;

    cout << "Using Two-Level Binary Search: ";
    cout << (twoLevelBinarySearch(matrix, target) ? "Found" : "Not Found") << endl;

    return 0;
}
