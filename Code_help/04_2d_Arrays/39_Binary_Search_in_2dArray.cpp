#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target){
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row*col-1;

    int mid = start+(end - start)/2;

    while(start<=end){
        int element = matrix[mid/col][mid%col];

        if(element == target){
            return 1;
        }

        if(element < target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return 0;
}

// Search 'target' element in such 'matrix' where:
// 1. Each row are sorted in ascending 
// 2. Each column are sorted in ascending 
bool searchSortedMatrix(vector<vector<int>> &matrix, int target){
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col-1;

    while(rowIndex < row && colIndex >= 0){
        int element = matrix[rowIndex][colIndex];

        if(element == target)
            return 1;
        
        if(element < target){
            rowIndex++;
        }
        else{
            colIndex--;
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout<<searchSortedMatrix(mat, 15);
    return 0;
}