#include <iostream>

using namespace std;

// This function check wether we can fill the containers with the vessel if we set the maximum container space to be max
bool can_fill(size_t c[], size_t m, size_t n, size_t max) {
	size_t current_container = 1;
	size_t current_val = 0;
	
	for(size_t i = 0; i < n; i++) {
		
		if(c[i] > max) return false;
		
		if(c[i] + current_val > max) {
			if(current_container == m) return false;
			current_container ++;
			current_val = c[i];
		} else {
			current_val += c[i];
		}
	}
	
	return true;
}


int main() {
	
	size_t n,m;
	
	while(cin >> n >> m) {
				
		//getting input
		size_t c[n];
		
		
		for(size_t i = 0; i < n; i++) {
			cin >> c[i];
		}
		
		size_t L, U, ans;
		L = 1;
		U = 100000000;
		
		//binary search of optimal solution
		while(L <= U) {
			
			size_t middle = (L + U) / 2;
			
			if(can_fill(c, m, n, middle)) {
				U = middle - 1;
				ans = middle;
			} else {
				L = middle + 1;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
