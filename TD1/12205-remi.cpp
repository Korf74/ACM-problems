#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
	
	size_t N, M; // N is the number of phones, M the number of intervals
	
	// main loop
	while((cin >> N >> M) && (N != 0 && M != 0)) {
		int calls[N][4];
		int intervals[M][2];
		
		
		//getting calls
		for(size_t i = 0; i < N; i++) {
			for(int j = 0; j < 4; j++) {
				cin >> calls[i][j];
			}
		}
		
		//getting intervals
		for(size_t i = 0; i < M; i++) {
			for(int j = 0; j < 2; j++) {
				cin >> intervals[i][j];
			}
		}
		
				
		for(size_t i = 0; i < M; i++) { // for each interval
			size_t ans = 0;
			int beg = intervals[i][0];
			int end = intervals[i][1] + beg;
			
			for(size_t j = 0; j < N; j++) { // for each call
				int call_beg = calls[j][2];
				int call_end = call_beg + calls[j][3];
				
				if(min(end, call_end) - max(beg, call_beg) >= 1) {
					ans ++;
				}
			}
			
			cout << ans << endl;
		}
	}
	
	return 0;
	
}

