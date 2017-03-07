#include <iostream>
#include <stdint.h>


using namespace std;

uint64_t vabs(uint64_t a) {
	return a < 0 ? -a : a;
}

uint64_t mod(uint64_t a, uint64_t m) {
	
	while(a >= m) {
		a -= m;
	}
	
	return a;
}

uint64_t gcd(uint64_t a, uint64_t b) {
	
	uint64_t c = 0;
	
	while(b > 0) {
		c = mod(a, b);
		a = b;
		b = c;
	}
	
	return a;
}

int main() {
	int pb(0);
	int c;
	
	cin >> pb;
	
	while(cin >> c) {
				
		uint64_t a[c];
		uint64_t a10[c];
		uint64_t tmp;
		uint64_t maxS = 0;
		uint64_t g = 0;
		
		for(int i = 0; i < c; ++i) {
			a[i] = 0;
			
			for(int j = 0; j < 9; ++j) {
				cin >> tmp;
				a[i] += tmp;
			}
			
			cin >> tmp;
			a10[i] = tmp;
			
			maxS = max(maxS, tmp);
			
			g = gcd(g, vabs(a10[i] - a[i]));
		}
		
		if(g > 1 && maxS < g) {
			cout << g << endl;
		} else {
			cout << "impossible" << endl;
		}
		
		
	}
}
