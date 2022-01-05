// Find the total number of occurences of an element in an array 
// Total No. of Occurences = (Last index - First index) + 1
// if element is not present, output is -1

#include<bits/stdc++.h>
using namespace std;
int firstOcc(int arr[], int n, int key){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            e =mid-1;
        }
        else if(arr[mid] > key){
            e = mid - 1;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
int lastOcc(int arr[], int n, int key){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            s =mid+1;
        }
        else if(arr[mid] > key){
            e = mid - 1;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(int arr[], int n, int key){
    int a = firstOcc(arr, n, key);
    int b = lastOcc(arr, n, key);
    return pair<int, int>(a,b);
}

// Total No. Occurences of an element
int totalOcc(int arr[], int n, int k){
    pair<int, int> p = firstAndLastPosition(arr, n, k);
    if(p.first == -1 || p.second == -1){
        return -1;// represents that element does not exist in array
    }
    else{
        return (p.second - p.first)+1;
    }
}
int main()
{
    int arr[100],key;
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Element : ";
    cin >> key;

    int count = totalOcc(arr, n, key);
    if(count == -1){
        cout<<"The element '"<<key<<"' doesn't appeared at all"<<endl;
    }
    else{
        cout<<"The element '"<<key<<"' appeared "<<count<<" times.";
    }
    return 0;
}
/* sample input 
7
1 2 3 3 3 3 5
3
*/
