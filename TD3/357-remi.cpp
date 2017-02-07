#include <iostream>

using namespace std;

#define COINS 5

/**
 * possible coins 1, 5, 10, 25, 50
 * */


int main() {
	
	int n;
	int coins[] = {1, 5, 10, 25, 50};
	
	while(cin >> n) {
		
		size_t D[n + 1][COINS];
		
		for(int i = 0; i < COINS; i++) {
			D[0][i] = 1;
		}
		
		
		// Bottom up dynamic programming
		for(int change = 1; change <= n; change ++) {
			for(int coin = COINS - 1; coin >= 0; coin --) {
				
				int new_change = change - coins[coin];
				
				if(new_change < 0) {
					
					D[change][coin] = 0;
					
				} else {
					
					D[change][coin] = (coin == COINS - 1 ? D[new_change][coin] : D[new_change][coin] + D[change][coin + 1]);
				}
			}
		}
		
		size_t ans = D[n][0];
		
		if(ans == 1) cout << "There is only 1 way to produce " << n << " cents change." << endl;
		else cout << "There are " << ans << " ways to produce " << n << " cents change." << endl;
	}
	
	
	return 0;
	
	
}
