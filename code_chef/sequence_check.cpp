#include<bits/stdc++.h>
using namespace std;

bool is_possible(int *s, int n){
    bool valley_is_reached=false,
         peak_is_reached=false,
         is_decreasing=true,
         is_increasing=true,
         continuity_broke=false;

    for(int i=0; i<n-1; i++){
        if(s[i]>s[i+1] && is_decreasing){
            is_increasing = false;
        }
        else if(s[i]<s[i+1] && is_increasing){
            is_decreasing = false;
        }
        else{
            continuity_broke=true;
            // cout<<"continuity broke";
            break;
        }
    }
    if(!continuity_broke){
        return true;
    }
    for(int i=0; i<n-1; i++){
        if(s[i-1]>s[i] && s[i]<s[i+1] && i>0){
            valley_is_reached = true;
        }
        else if(!valley_is_reached && s[i]>s[i+1]){
            continue;
        }
        else if(valley_is_reached && s[i]<s[i+1]){
            continue;
        }
        else{
            peak_is_reached=true;
            // cout<<"Peak reached"<<endl
            //     <<"i = "<<i;

            break;
        }
    }
    if(peak_is_reached){
        return false;
    }
    else{
        // cout<<"Peak is not reached";
        return true;
    }
}

int main()
{
    int n;
    cin>>n; 
    int *s = new int[n];

    for(int i=0; i<n; i++){
        cin>>s[i];
    }

    if(is_possible(s, n)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

    return 0;
}