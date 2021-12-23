#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int , int> occurenceMap;
        for (int i=0; i<arr.size(); i++){
            occurenceMap.insert(pair<int, int>(arr[i],0));
        }
        for (int i=0; i<arr.size(); i++){
            occurenceMap.insert(pair<int, int>(arr[i],));
        }
    }
};
int main()
{
    
    return 0;
}