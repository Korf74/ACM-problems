#include <iostream>
#include <stdint.h>
using namespace std;

int64_t max(int64_t a, int64_t b) {
	return (a > b ? a : b);
}


int main() {
	uint32_t N(0);
	
	while(cin >> N) {
	
		int64_t A[N][N];
		
		int64_t tmp;
		for(uint32_t i = 0; i < N; ++i) {
			for(uint32_t j = 0; j < N; ++j) {
				cin >> tmp;
				if(j == 0) {
					A[i][j] = (i == 0 ? tmp : tmp + A[i - 1][j]);
				} else {
					A[i][j] = (i == 0 ? tmp + A[i][j - 1] : tmp + A[i][j - 1] + A[i - 1][j] - A[i - 1][j - 1]);
				}
			}
		}
				
		int64_t max_sum = A[0][0];
		
		for(uint32_t i = 0; i < N; ++i) {
			for(uint32_t j = 0; j < N; ++j) {
				
				max_sum = max(max_sum, A[i][j]);
				
				for(uint32_t k = 1; k <= j; ++k) {
					max_sum = max(max_sum, (A[i][j] - A[i][j - k]));
				}
				
				for(uint32_t k = 1; k <= i; ++k) {
					max_sum = max(max_sum, (A[i][j] - A[i - k][j]));
				}
				
				for(uint32_t k = 1; k <= i; ++k) {
					for(uint32_t l = 1; l <= j; ++l) {
						max_sum = max(max_sum, (A[i][j] - A[i - k][j] - A[i][j - l] + A[i - k][j - l]));
					}
				}
				
			}
		}
		
		cout << max_sum << endl;
	}
	
	return 0;
}
