#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>

using namespace std;

#define LION 1
#define TIGER 2
#define LEOPARD 3
#define PANTHER 4


bool search(unsigned int idx, vector<unsigned int> E[101], unsigned int V[101], unsigned int color[101], bool visited[101], unsigned int vertices) {
	
	if(idx == vertices) return true;
	
	for(int c = idx == 0 ? PANTHER : LION; c <= PANTHER; ++c) {
		bool ok = true;
		unsigned int u = V[idx];
		
		for(size_t i = 0; i < E[u].size(); ++i) {
			if(visited[E[u][i]] && color[E[u][i]] == (unsigned int)c) {
				ok = false;
			}
		}
		if(ok) {
			visited[u] = true;
			color[u] = c;

			if(dfs(idx + 1, E, V, color, visited, vertices)) return true;
			
			visited[u] = false;
		}
		
	}
		
	return false;
	
}

void bfs(unsigned int init, vector<unsigned int> E[101], unsigned int V[101], unsigned int color[101], bool visited[101]) {
	bool used[101];
	queue<int> Q;
	unsigned int u;
	unsigned int vertices = 0;
	Q.push(init), visited[init] = true;
	while (!Q.empty()) {
		u = Q.front(), Q.pop();
		V[vertices++] = u;
		for (size_t i = 0; i < E[u].size(); i++) {
			int v = E[u][i];
			if (!visited[v]) {
				visited[v] = true;
				Q.push(v);
			}
		}
	}
	memset(used, false, sizeof(used));
	search(0, E, V, color, used, vertices);
}

int main() {
	
	unsigned int N(0);
	int pb(0);
	
	vector<unsigned int> E[101]; // Edges
	unsigned int V[101]; // Vertices
	bool visited[101];
	unsigned int color[101]; // colors
	
	for(unsigned int i = 1; i <= N; i++) {
		vector<unsigned int> v;
		E[i] = v;
				
	}
	
	char line[128];
	
	while(cin >> N) {
		if(pb != 0) cout << endl;
		
		for(unsigned int i = 1; i <= N; i++) {
			E[i].clear();
		}
		
		memset(visited, false, sizeof(visited));
		memset(color, 0, sizeof(color));
		memset(V, 0, sizeof(V));
		
		unsigned int a, b;
		
		
		while (getchar() != '\n'); 
		
		while(gets(line)) {
			
			if(line[0] == '\0') break;
			
			sscanf(line, "%u-%u", &a, &b);
					
   			if(!contains(E[a], b)) E[a].push_back(b);
				
			if(!contains(E[b], a)) E[b].push_back(a);
			
			
		}

		for (unsigned int i = 1; i <= N; i++) {
			sort(E[i].begin(), E[i].end());
		}
		
		for(unsigned int i = 1; i <= N; ++i) {
			if(!visited[i]) {
				bfs(i, E, V, color, visited);
			}
		}
		
		for(unsigned int i = 1; i <= N; i++) {
			cout << i << " " << color[i] << endl;
		}
		
		++pb;
		
		
	}
	
}
