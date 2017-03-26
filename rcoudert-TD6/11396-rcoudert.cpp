#include <iostream>
#include <vector>
#include <stdint.h>
#include <queue>
#include <string.h>

using namespace std;


bool bfs(uint32_t init, vector<uint32_t> E[301], unsigned char color[301], bool visited[301]) {

	queue<int> Q;
	Q.push(init);
	visited[init] = true;
	uint32_t u = init;
	uint32_t v = init;
	
	color[init] = 1;
	
	while (!Q.empty()) {
		
		u = Q.front(), Q.pop();
						
		for (size_t i = 0; i < E[u].size(); i++) {
			
			v = E[u][i];
			
			if(color[v] == color[u]) return false;
			
			if (!visited[v]) {
				
				visited[v] = true;
				color[v] = (color[u] == 1 ? 2 : 1);
				Q.push(v);
				
			}
		}
		
	}
	
	return true;
}


int main() {
	
	uint32_t n(0);
	unsigned char color[301];
	bool visited[301];
	vector<uint32_t> E[301];
	
	for(uint32_t i = 0; i < 301; ++i) {
		vector<uint32_t> v;
		E[i] = v;
	}
	
	cin >> n;
	
	while(n != 0) {
		
		memset(color, 0, sizeof(color));
		memset(visited, false, sizeof(visited));
						
		for(uint32_t i = 0; i < 301; ++i) {
			E[i].clear();
		}
		
		uint32_t a, b;
		cin >> a >> b;
		
		while(a != 0 || b!= 0) {
			E[a].push_back(b);
			E[b].push_back(a);
			cin >> a >> b;
		}
		
		bool ans = true;
		uint32_t u = 1;
		
		while(ans && u <= n) {
			if(!visited[u]) ans = ans && bfs(u, E, color, visited);
			++u;
		}
		
		cout << (ans ? "YES" : "NO") << endl;
		
		cin >> n;
		
	}
	
}
