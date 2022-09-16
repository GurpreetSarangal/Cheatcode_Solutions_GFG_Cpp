#include <iostream>
using namespace std;

void best_buy(int X, int Y, int N, long int R){
    long int normal_best = -1, prem_best = -1;

    
    if(X * N > R){
        cout << -1 <<endl;
        return;
    }
    
    long int n_start, m_start, 
        n_end  , m_end,
        n_mid  , m_mid;
        
    n_start = m_start = 0;
    n_end = m_end = N;
    
    while(n_start <= n_end && m_start <= m_end){
        n_mid = n_start + (( n_end - n_start )/2);
        m_mid = m_start + (( m_end - m_start + 1 )/2);
        
        long int D_P = (X * n_mid) + (Y * m_mid);
        // cout << " dp -> " << D_P << endl
        //     << " n_mid " << n_mid <<endl
        //     << " m_mid " << m_mid <<endl;
            
        if (n_mid == 0 && m_mid == N){
            normal_best = n_mid;
            prem_best = m_mid;
            break;
        }
        
        if( (R - D_P < Y && R - D_P > 1) || D_P == R){
            normal_best = n_mid;
            prem_best = m_mid;
            // cout<<" normal_best " << normal_best <<endl 
            //     <<" prem_best " << prem_best <<endl;
            break;
        }
        else if(D_P > R){
            n_start = n_mid + 1;
            m_end = m_mid - 1;
            // cout<< " D_P > R -> "<<endl
            //     << " n_start " << n_start << endl
            //     << " m_end " << m_end << endl;
        }
        else if(R - D_P >= Y){
            m_start = (m_mid + 1);
            n_end = (n_mid - 1);
            // cout<< " R - D_P > Y -> " <<endl
            //     << " n_end " << n_end <<endl
            //     << " m_start " << m_start << endl;
        }
    }
    
    
    if( normal_best == -1 && prem_best == -1){
        cout<<-1<<endl;
    }
    else{
        cout<<normal_best<< " " << prem_best<<endl;
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
