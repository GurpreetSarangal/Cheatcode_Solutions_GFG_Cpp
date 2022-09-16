#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int>);
vector<int> spiralOrder(vector<vector<int>> &matrix){

    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    int total = row*col;

    // index initialization
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;
    
    while(count < total){
        // print starting row

        for(int index = startingCol; count<total && index <= endingCol; index++){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;
        printArray(ans);
        // print ending column
        for(int index = startingRow; count<total && index <= endingRow; index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;
        printArray(ans);

        // print ending row
        for(int index = endingCol; count<total && index>=startingCol; index--){
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;
        printArray(ans);

        // print starting column
        for(int index = endingRow; count<total && index >= startingRow; index--){
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
        printArray(ans);
    }
    return ans;
}

void printArray(vector<int> arr){
    for(int i:arr){
        cout<<i<<"  ";
    }cout<<endl;
}

int main()
{
    vector<vector<int>> mat = {{1,2,3,5,234,3,3,42},{4,5,6,44,6,5,3,4},{7,8,9,3,2,2,3,4}};
    vector<int> ans = spiralOrder(mat);
    printArray(ans);
    return 0;
}