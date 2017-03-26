#include <stdint.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

void DFS(uint32_t u, vector<uint32_t>* E, bool* visited, vector<uint32_t>& topo_sort) {
	
	visited[u] = true;
	
	for(uint32_t i = 0; i < E[u].size(); ++i) {
		
		uint32_t v = E[u][i];
				
		if(!visited[v]) {
			DFS(v, E, visited, topo_sort);
		}
	}
	
	topo_sort.push_back(u);
	
}

int main() {
	
	uint32_t tests = 0;
	uint32_t n(0), m(0);
	
	cin >> tests;
	
	while(tests-- > 0) {
		cin >> n >> m;
		
		vector<uint32_t> E[n + 1];
		vector<uint32_t> topo_sort;
		bool visited[n + 1];
		
		memset(visited, false, n + 1 * sizeof(bool));
		
		for(uint32_t i = 1; i <= n; ++i) {
			vector<uint32_t> v;
			E[i] = v;
		}
		
		uint32_t a, b;
		
		for(uint32_t i = 0; i < m; ++i) {
			cin >> a >> b;
			E[a].push_back(b);
		}
		
		for(uint32_t i = 1; i <= n; ++i) {
			if(!visited[i]) {
				DFS(i, E, visited, topo_sort);
			}
		}
		
		reverse(topo_sort.begin(), topo_sort.end());
		
		memset(visited, false, n + 1 * sizeof(bool));
		
		uint32_t ans = 0;
		
		for(uint32_t i = 0; i < n; ++i) {
			
			uint32_t u = topo_sort[i];
			
			if(!visited[u]) {
				DFS(u, E, visited, topo_sort);
				++ans;
			}
			
		}
		
		cout << ans << endl;
		
		
	}
}
