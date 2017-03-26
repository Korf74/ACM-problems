#include <iostream>
#include <vector>
#include <stdint.h>
#include <queue>
#include <string.h>

using namespace std;


void bfs(uint32_t init, vector<uint32_t> E[1000], uint32_t GN[1000], bool visited[1000]) {

	queue<int> Q;
	Q.push(init), visited[init] = true;
	uint32_t GN_nb = 0;
	uint32_t u = init;
	uint32_t v = init;
	
	while (!Q.empty()) {
		
		u = Q.front(), Q.pop();
		
		if(GN[u] > GN_nb) ++GN_nb;
		
		for (size_t i = 0; i < E[u].size(); i++) {
			
			v = E[u][i];
			
			if (!visited[v]) {
				
				visited[v] = true;
				GN[v] = GN_nb + 1;
				Q.push(v);
				
			}
		}
		
	}
}


int main() {
	
	uint32_t C(0), P(0), D(0);
	uint32_t GN[1000];
	bool visited[1000];
	vector<uint32_t> E[1000];
	
	for(uint32_t i = 0; i < 1000; ++i) {
		vector<uint32_t> v;
		E[i] = v;
	}
	
	cin >> C;
	
	while(C-- > 0) {
		
		memset(GN, 0, sizeof(GN));
		memset(visited, false, sizeof(visited));
		
		cin >> P >> D;
				
		for(uint32_t i = 0; i < 1000; ++i) {
			E[i].clear();
		}
		
		uint32_t a, b;
		
		for(uint32_t i = 0; i < D; ++i) {
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		
		for(uint32_t i = 0; i < P; ++i) {
			if(!visited[i]) bfs(i, E, GN, visited);
		}
		
		for(uint32_t i = 1; i < P; ++i) {
			cout << GN[i] << endl;
		}
		
		if(C != 0) cout << endl;
		
	}
	
}
