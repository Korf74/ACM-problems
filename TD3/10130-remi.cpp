#include <iostream>

using namespace std;

int main() {
	
	int T;
	
	cin >> T;
	
	while(T > 0) {
		
		
		//getting input
		int N;
		cin >> N;
		int P[N], W[N];
		
		for(int i = 0; i < N; i++) {
			cin >> P[i] >> W[i];
		}
		
		int G;
		cin >> G;
		int MW[G];
		
		for(int i = 0; i < G; i++) {
			cin >> MW[i];
		}
		
		
		//computation
		int ans = 0;
		
		// D[i][j] = max value possible starting from object j + 1 and with weigth i
		
		//For each person, take or not the object and take the max of final value
		for(int p = 0; p < G; p ++) {
			
			int D[MW[p] + 1][N];
			
			for(int i = 0; i <= MW[p]; i++) {
			
				for(int j = N - 1; j >= 0; j--) {
					
					if(i == 0) {
						
						D[i][j] = 0;
						
					} else if(i >= W[j]) {
						
						D[i][j] = j == N - 1 ? P[j] : max(
															D[i][j + 1],
															P[j] + D[i - W[j]][j + 1]
														 );
						
					} else {
						
						D[i][j] = (j == N - 1 ? 0 : D[i][j + 1]);
						
					}
					
					
				}
			}
							
			ans += D[MW[p]][0];
		}
		
		//output
		cout << ans << endl;
		
		
		T--;
	}
	
}
