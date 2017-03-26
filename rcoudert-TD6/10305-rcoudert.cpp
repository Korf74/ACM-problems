#include <iostream>
#include <vector>
#include <stdint.h>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

void topological_sort(vector<uint32_t> E[101], uint32_t indegree[101], vector<uint32_t>& seq, uint32_t n) {
	
	queue<uint32_t> q;
	uint32_t u;
	
	for(uint32_t i = 1; i <= n; ++i) {
		if(indegree[i] == 0) q.push(i);
	}
	
	while(!q.empty()) {
		u = q.front(), q.pop();
		seq.push_back(u);
		
		for(uint32_t i = 0; i < E[u].size(); ++i) {
			uint32_t v = E[u][i];
			--indegree[v];
			
			if(indegree[v] == 0) {
				q.push(v);
			}
		}
	}
	
}


int main() {
	
	uint32_t n(0), m(0);
	vector<uint32_t> seq;
	vector<uint32_t> E[101];
	uint32_t indegree[101];
	
	for(uint32_t i = 0; i < 101; ++i) {
		vector<uint32_t> v;
		E[i] = v;
	}
	
	cin >> n >> m;
	
	while(n != 0 || m != 0) {
		
		seq.clear();
		
		memset(indegree, 0, sizeof(indegree));
						
		for(uint32_t i = 1; i < 101; ++i) {
			E[i].clear();
		}
		
		uint32_t a, b;
		
		for(uint32_t i = 0; i < m; ++i) {
			cin >> a >> b;
			E[a].push_back(b);
		}
		
		for(uint32_t i = 1; i <= n; ++i) {
			for(uint32_t j = 0; j < E[i].size(); ++j) {
				++indegree[E[i][j]];
			}
		}
		
		
		topological_sort(E, indegree, seq, n);
		
		for(uint32_t i = 0; i < n; ++i) {
			cout << seq[i];
			if(i != n - 1) cout << " ";
		}
		
		cout << endl;
		
		cin >> n >> m;
		
	}
	
}
