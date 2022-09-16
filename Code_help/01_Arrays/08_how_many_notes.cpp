#include<bits/stdc++.h>
using namespace std;
void number_of_notes(int num);

int main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    number_of_notes(num);
    return 0;
}

void number_of_notes(int num){
    int divide_by, arr[4];
    for (int i=0; i<4; i++){
        switch (i)
        {
        case 0:
            divide_by=100;
            break;
        
        case 1:
            divide_by = 50;
            break;
        
        case 2:
            divide_by=20;
            break;
        
        case 3:
            divide_by = 1;
            break;
        }

        arr[i] = num/divide_by;
        num=num%divide_by;

    }
    cout<<arr[0]<<" :100\n"
        <<arr[1]<<" :50\n"
        <<arr[2]<<" :20\n"
        <<arr[3]<<" :1\n";


}