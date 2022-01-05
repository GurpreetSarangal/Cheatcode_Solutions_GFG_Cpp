#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums){
    int i=0;
    for(int j=0; j<nums.size(); j++){
        if(nums[j] != 0){
            swap(nums[j] , nums[i]);
            i++;
        }
    }
}

void printArray(vector<int> arr){
    for(int i:arr){
        cout<<i<<"  ";
    }cout<<endl;
}
int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    printArray(nums);
    moveZeroes(nums);
    printArray(nums);

    return 0;
}