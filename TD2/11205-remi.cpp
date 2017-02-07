#include <iostream>

using namespace std;


// This function checks if there are i,j i!=j s.t. a[i] == a[j]
bool exists_doubles(int a[], int size) {
	for(int i = 0; i < size; i++) {
		for(int j = i + 1; j < size; j++) {
			if(a[i] == a[j]) return true;
		}
	}
	
	return false;
}

// This function calculates the number of bits at 1 in a
int nm_bits(int a) {
	int b = 0;
	while(a > 0) {
		b += (a & 1);
		a = a >> 1;
	}
	
	return b;
}


int main() {
	
	int problems;
	
	cin >> problems;
	
	while(problems > 0) {
		
		//Getting input
		int P, N;
		cin >> P >> N;
		
		int s[N];
		
		for(int i = 0; i < N; i++) {
			int a, b;
			for(int j = 0; j < P; j++) {
				cin >> a;
				b = (b << 1) + a;
			}
			s[i] = b;
		}
		
		// a is the mask, we check each time that if we shut down some leds there are no double symbols
		int ans = P;
		int a = 0;
		int s2[N];
		
		while(a < (1 << P)) {
			for(int i = 0; i < N; i++) {
				s2[i] = s[i] & a;
			}
			int bits = nm_bits(a);
			if(!exists_doubles(s2, N) && bits < ans) ans = bits;
			a ++;
		}
		
		
		cout << ans << endl;		
		
		
		problems --;
	}
	
	return 0;
}
