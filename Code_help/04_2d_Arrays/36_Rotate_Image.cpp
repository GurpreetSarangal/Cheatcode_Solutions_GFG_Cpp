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
class Solution {
public:
    void nextToBeRotated(pair<int,int> &p, int n){ // find next element to be rotated
        int a = p.first;
        p.first = p.second;
        p.second = n-1-a;
    }
    void change(vector<vector<int>>& matrix, pair<int,int> p, int n){
        int i=0;
        int temp = matrix[p.first][p.second];
        while(i<4){ // every time we have to rotate 4 elements
            nextToBeRotated(p,n); // next element to be rotated
            int temp2 = matrix[p.first][p.second]; // store its value
            matrix[p.first][p.second] = temp; // replace it with the previous one
            temp = temp2; // store the next 'previous' value
            i++;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        int i = 0;
		// we take (n^2)/4 elements to start the rotation: 
		// in example 1 we take 1,2; in example 2: 5,1,9,4.
        while(i<(n+1)/2-1){ 
            for(int j=i;j<n-i-1;j++) change(matrix, make_pair(i,j), n);
            i++;
        }
		// if the size of the matrix is odd, we don't need to rotate the last element
        if(n%2==0) change(matrix, make_pair((n-1)/2,(n-1)/2),n); 
    }
    
};

int main()
{
    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printArray(mat);
    rotate(mat);
    printArray(mat);
    return 0;
}