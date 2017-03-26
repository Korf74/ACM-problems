#include <iostream>
#include <cmath>
#include <cstring>


using namespace std;


size_t fibonacci(int n, unsigned int mask)
{
    size_t fib[2][2] = {{1,1},{1,0}}, ret[2][2] = {{1,0},{0,1}}, tmp[2][2] = {{0,0},{0,0}};
    int i, j, k;
    
    while(n > 0)
    {
        if(n & 1)
        {
            memset(tmp, 0, sizeof tmp);
            for(i = 0; i  <2; i++) {
				 for(j=0; j < 2; j++) for(k = 0; k < 2; k++) {
                        tmp[i][j] = (tmp[i][j] + ret[i][k] * fib[k][j]);
					}
			}
            for(i = 0; i < 2; i++) {
				for(j = 0; j < 2; j++) {
					ret[i][j] = tmp[i][j];
				}
			}
        }
        memset(tmp, 0 ,sizeof tmp);
        for(i = 0; i < 2; i++) {
			 for(j = 0; j < 2; j++) {
				 for(k = 0; k < 2; k++)
                    tmp[i][j] = (tmp[i][j] + fib[i][k] * fib[k][j]);
				}
			}
        for(i = 0; i < 2; i++) {
			for(j=0; j < 2; j++) {
				  fib[i][j] = tmp[i][j] & mask;
			}
		}
        n /= 2;
    }
    return (ret[0][1] & mask);
}

int main() {
	
	
	size_t n;
	unsigned int m;
	
	while(cin >> n >> m) {
		
		int mask = m == 0 ? 0 : 1;
		
		for(size_t i = 1; i < m; i++) {
			mask = (mask << 1) | 1;
		}
				
		cout << fibonacci(n, mask) << endl;
		
		
	}
	
	return 0;
}
