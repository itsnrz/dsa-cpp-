// to find maximum row and column sum of a matrix along with corresponding row and column.


#include<iostream>
#include<vector>
#include<utility>
#include<climits>
using namespace std;
// func to find max row sum and that row 
pair<int,int> max_rowSum(vector<vector<int>>matrix){
    if (matrix.empty() || matrix[0].empty()) return {0, -1};
    int maxsum= INT_MIN,row=0,rows=matrix.size(),cols=matrix[0].size();
    for(int i=0;i<rows;i++){
        int rsum=0;
        for(int j=0;j<cols;j++){
            rsum+=matrix[i][j];
        }
        if(maxsum<rsum){
            maxsum=rsum;
            row=i;
        }      
    }
    return {maxsum,row};
}
// func to find maximum column sum and that column
pair<int,int> max_colSum(vector<vector<int>>matrix){
    if (matrix.empty() || matrix[0].empty()) return {0, -1};
    int maxsum= INT_MIN,col=0,cols=matrix[0].size(),rows=matrix.size();
    for(int i=0;i<cols;i++){
        int csum=0;
        for(int j=0;j<rows;j++){
            csum+=matrix[i][j];
        }
        if(maxsum<csum){
            maxsum=csum;
            col=i;
        }      
    }
    return {maxsum,col};
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
    pair<int,int>resr=max_rowSum(mat);
    pair<int,int>resc=max_colSum(mat);
    cout<<"maximum sum of row in this matrix = "<<resr.first<<" in row = "<<resr.second<<endl;
    cout<<"maximum sum of col in this matrix = "<<resc.first<<" in col = "<<resc.second<<endl;
}