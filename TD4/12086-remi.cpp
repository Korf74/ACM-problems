#include <iostream>
#include <vector>
#include <stdlib.h>


using namespace std;


int sum(int x, int y, const vector<int>& t) {
  if(x == 1) {
    int res = 0;
    while(y > 0) {
      res += t[y];
      y -= (y & -y);
    }
    return res;
  }
  else
    return sum(1, y, t) - sum(1, x - 1, t);
}

void inc(int x, int inc, vector<int>& t) {
  while(x < int(t.size())) {
    t[x] += inc;
    x += (x & -x);
  }
}


int main() {
	
	size_t N = 0;
	int pb = 1;
	
	cin >> N;
	
	while(N != 0) {
		
		if(pb != 1) cout << endl;
		
		int pots[N + 1];
		
		cout << "Case " << pb << ":" << endl;
		
		vector<int> R;
		
		R.assign(N + 1, 0);
		
		for(size_t i = 1; i <= N; i++) {
			int a;
			cin >> a;
			pots[i] = a;
			inc(i, a, R);
			
		}
		
		string action = "";
		cin >> action;
		
		while(action != "END") {
			
			if(action == "M") {
				
				int x,y;
				
				cin >> x >> y;
								
				cout << sum(x, y, R) << endl;
								
			} else if(action == "S") {
				
				int x, r;
				
				cin >> x >> r;
				
				inc(x, r - pots[x], R);
				
				pots[x] = r;
				
				
			}
			
			cin >> action;
			
		}		
		
		pb ++;
		cin >> N;
	}
	
}
