#include <iostream>
#include <stdint.h>
#include <cmath>
#include <vector>

using namespace std;

uint64_t LIMIT = 1000000000000L;
vector<uint64_t> almost_primes;


bool is_prime(uint64_t n) {
	if(n == 2) return true;
	
	for(uint64_t i = 2; i <= sqrt(n); ++i) {
		if(n % i == 0) return false;
	}
	
	return true;
}


void almost_primes_from(uint64_t n) {
	
	uint64_t tmp = n * n;
	
	while(tmp < LIMIT) {
		almost_primes.push_back(tmp);
		tmp *= n;
		
	}
	
}

int main() {
	int N(0);
	
	uint64_t low, high;
	
	cin >> N;
		
	for(uint32_t i = 2; i < 1000000; ++i) {
		if(is_prime(i)) {
			almost_primes_from(i);
		}
	}
	
	
	size_t s = almost_primes.size();
	
	while(cin >> low >> high) {
		
		uint32_t ans = 0;
		
		for(size_t i = 0; i < s; ++i) {
			if(low <= almost_primes[i] && almost_primes[i] <= high) {
				++ans;
			}
		}
		
		cout << ans << endl;
		
	}
	
	return 0;
}
