#include <iostream>


using namespace std;


size_t mod(size_t x, size_t n) {
	return x - ((x / n) * n);
}

size_t fastexp(size_t x, size_t y, size_t n) {
	if(y == 0) return 1;
	if(y == 1) return x;
	
	if((y / 2) * 2 == y) {
		size_t tmp = mod(fastexp(x, y / 2, n), n);
		return mod(tmp * tmp, n);
	} else {
		return mod(mod(x, n) * mod(fastexp(x, y - 1, n), n), n);
	}
}


int main() {
	
	size_t c = 0;
	
	cin >> c;
	
	size_t x, y, n;
	
	for(; c > 0; c--) {
		cin >> x >> y >> n;
		
		cout << fastexp(x, y, n) << endl;
		
	}
	
}
