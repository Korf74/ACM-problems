#include <iostream>


using namespace std;


#define MAX_D 20



int mod(int a, int p) {
	if(a >= 0) {
		return (a % p); 
	}
		
	
	while(a < 0) { 
		a += p; 
	}
	
	return a;
}


int main() {
	
	int N, Q;
	int set(1);
	
	
	while(cin >> N >> Q && (N != 0 && Q != 0)) {
		
		cout << "SET " << set << ":" << endl;
		
		//getting input
		int nb[N];
		int qu[Q][2];
		
		for(int i = 0; i < N; i ++) cin >> nb[i];
		for(int i = 0; i < Q; i ++) cin >> qu[i][0] >> qu[i][1];
		
		
		for(int q = 0; q < Q; q++) {
			
			int D = qu[q][0];
			int M = qu[q][1];
					
			// S[i][j][k] := number of sums starting at i with j numbers which added to k are divisible by D
			size_t S[N][M + 1][D];
			
			
			for(int i = N - 1; i >= 0; i--) {
				
				for(int j = 1; j <= M; j++) {
					
					for(int k = 0; k < D; k++) {
						
						S[i][j][k] = 0;
						
						
						int s = mod(k + nb[i], D);						
						size_t a = (i == N - 1 ? 0 : S[i + 1][j][k]);
						
						if(j == 1) {
							
							if(s == 0) {
								
								S[i][j][k] = 1 + a;
								
							} else {
								
								S[i][j][k] = a;
								
							}
						
							
						} else {
							
							if(i == N - 1) {
								S[i][j][k] = 0;
							} else {
								S[i][j][k] = S[i + 1][j][k] + S[i + 1][j - 1][s];
							}
							
						}
						
						//cout << "S[" << i << "][" << j << "][" << k << "] : " << S[i][j][k] << endl;
					}
					
				}
				
			}
			
			cout << "QUERY " << q + 1 << ": " << S[0][M][0] << endl;
		}
		
		
		++set;
	}
	
}
