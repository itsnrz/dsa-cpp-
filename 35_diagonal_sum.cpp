// 1572. Matrix Diagonal Sum(leet code)
// in this problem  we have given that the matrix is square matrix
/*class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
      if(mat.empty()||mat[0].empty())return 0;
      int ans=0,rsize=mat.size(),csize=mat[0].size();
      for(int i=0;i<rsize;i++){
        for(int j=0;j<csize;j++){
            if(i==j)ans+=mat[i][j];
            if((i+j)==rsize-1&&i!=j)ans+=mat[i][j];
        }
      } 
      return ans;
    }
};*/



// The Below Code Works for square and non-square matrices
#include<iostream>
#include<vector>
using namespace std;
int diagonal_Sum(vector<vector<int>>& mat) {
    if(mat.empty()||mat[0].empty())return 0;
    int ans=0,rsize=mat.size(),csize=mat[0].size();
    for(int i=0;i<rsize;i++){
        for(int j=0;j<csize;j++){
           if(i==j)ans+=mat[i][j];// primary sum
           else if (j==csize-i-1) ans+=mat[i][j];// secondary sum
        }
    }    
   return ans;
}
int optimized_sum(vector<vector<int>>& mat){// only for square matrix
    if(mat.empty()||mat[0].empty())return 0;
    int ans=0,rsize=mat.size();
    if(rsize != mat[0].size()) {
    cout << "Optimized sum works only for square matrices.\n";
    return -1;
     }
    for(int i=0;i<rsize;i++){
        ans+=mat[i][i];
        if(i!=rsize-i-1) ans+=mat[i][rsize-i-1];       
    }    
   return ans;
}
int main(){
    int r,c,val;
    cout<<"enter row and column size : ";
    cin>>r>>c;
    vector<vector<int>>mat;
    for(int i=0;i<r;i++){
        vector<int>row;
        for(int j=0;j<c;j++){
            cin>>val;
            row.push_back(val);
        }
        mat.push_back(row);
    }
    cout<<"diagonal sum of given matrix = "<<diagonal_Sum(mat)<<endl;
    cout<<"diagonal sum of given matrix(optimised approach) = "<<optimized_sum(mat)<<endl;
}
