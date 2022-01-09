#include<bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>>);
void rotate(vector<vector<int>>& matrix) {
    int row=0;
    int n=matrix.size();
    int firstRow[n];
    int lastCol[n];
    while(row<n-row){
        // copy first row in array
        cout<<"row -> "<<row<<endl;
        cout<<"copy first row in array"<<endl;
        for(int i=row; i<n-row; i++){
            firstRow[i] = matrix[row][i];
        }
        printArray(matrix);

        cout<<"copy last col in array"<<endl;
        for(int i=row; i<n-row; i++){
            lastCol[i] = matrix[i][n-row-1];
        }
        printArray(matrix);

        // first col to first row
        cout<<"first col to first row"<<endl;
        for(int i=row; i<n-row; i++){
            matrix[row][n-i-1] = matrix[i][row];
        }
        printArray(matrix);

        // last row to first col
        cout<<"last row to first col"<<endl;
        for(int i=row; i<n-row; i++){
            matrix[i][row] = matrix[n-row-1][i];
        }
        printArray(matrix);

        // last col to last row
        cout<<"last col to last row"<<endl;
        for(int i=row; i<n-row; i++){
            matrix[n-row-1][i] = lastCol[n-i-1];
        }
        printArray(matrix);

        // first row to last col
        cout<<"first row to last col"<<endl;
        for(int i=row; i<n-row; i++){
            matrix[i][n-row-1] = firstRow[i];
        }
        printArray(matrix);
        row++;
        cout<<"------------------"<<endl;
    }
}



void printArray(vector<vector<int>> arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printArray(mat);
    rotate(mat);
    printArray(mat);
    return 0;
}