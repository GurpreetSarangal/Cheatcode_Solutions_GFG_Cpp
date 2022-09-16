// This program arranges all negative elements to left side of the array WITHOUT maintaing the original order.
#include<bits/stdc++.h>
using namespace std;
void arrange(int arr[], int left, int right){
    while(left<=right){
        if(arr[left]<0 && arr[right]<0)
            left+=1;
        
        else if(arr[left]>0 && arr[right]<0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left += 1;
            right -= 1;
        }

        else if(arr[left]>0 && arr[right]>0)
            right -= 1;
        
        else{ // (arr[left]<0 && arr[right]>0)
            left += 1;
            right -= 1;
        }
    }
}

void display(int arr[], int right){
   
  for (int i=0;i<=right;++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main()
{
    int arr[] = {-2,-4,-21,-7, 87, 54, -4, -32};
    int arrsize = (sizeof(arr)/sizeof(arr[0]));
    arrange(arr,0, arrsize);
    display(arr, arrsize);
    return 0;
}