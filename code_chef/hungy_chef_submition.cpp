#include <iostream>
using namespace std;

void best_buy(int X, int Y, int N, long int R){
    // cout << X <<" "<< Y <<" "<< N <<" "<< R <<endl;
    if( R / Y >= N){
        cout<<0<<" "<<N<<endl;
    }
    else if ( R/X < N ){
        cout<< -1 <<endl;
    }
    else{
        int g = (Y * N);
        int f = (X - Y);
        int m = (R - g) / f;
        if((R-g) % f  !=  0){
            // cout<< m++ <<endl; 
            m++;
        }
        cout<< m << " "<<(N - m)<<endl;
    }
}

int main() {
	// your code goes here
	
	long int X, Y, N;
	long int R;
	int T;
	cin >> T;
	for(int i=0; i<T; i++){
	    
	    cin>>X>>Y>>N>>R;
	    best_buy(X, Y, N, R);
	}
	return 0;
}
