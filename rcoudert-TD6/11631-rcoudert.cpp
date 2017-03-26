#include <iostream>
#include <vector>
#include <stdint.h>
#include <string.h>
#include <algorithm>

#define LIMIT 200000

using namespace std;

// Union find datastructure http://stackoverflow.com/questions/8300125/union-find-data-structure
class UF {
  int *id, cnt, *sz;
  public:
// Create an empty union find data structure with N isolated sets.
UF(int N) {
    cnt = N; id = new int[N]; sz = new int[N];
    for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
~UF() { delete[] id; delete[] sz; }

// Return the id of component corresponding to object p.
int find(int p) {
    int root = p;
    while (root != id[root])    root = id[root];
    while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
    return root;
}
// Replace sets containing x and y with their union.
void merge(int x, int y) {
    int i = find(x); int j = find(y); if (i == j) return;
    // make smaller root point to larger one
    if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
    else { id[j] = i, sz[i] += sz[j]; }
    cnt--;
}
// Are objects x and y in the same set?
bool connected(int x, int y) { return find(x) == find(y); }
// Return the number of disjoint sets.
int count() { return cnt; }
};

uint32_t Kruskal(vector<pair<uint32_t, pair<uint32_t, uint32_t> > >& E, uint32_t n) {
	
	UF uf(n);
	uint32_t sum(0);
	
	sort(E.begin(), E.end());
	
	for(uint32_t i = 0; i < E.size(); ++i) {
		if(uf.find(E[i].second.first) != uf.find(E[i].second.second)) {
			sum += E[i].first;
			uf.merge(E[i].second.first, E[i].second.second);
		}
	}
	
	return sum;
}

int main() {
	uint32_t n(0), m(0);
	vector<pair<uint32_t, pair<uint32_t, uint32_t> > > E;
	uint32_t total_cost(0);
	
	
	cin >> m >> n;
	
	while(m != 0 || n != 0) {
		
		total_cost = 0;
		
		E.clear();
		
		uint32_t a, b, c;
		
		for(uint32_t i = 0; i < n; ++i) {
			cin >> a >> b >> c;
			pair<uint32_t, pair<uint32_t, uint32_t> > e;
			e.first = c;
			e.second.first = a;
			e.second.second = b;
			
			E.push_back(e);
			total_cost += c;
		}
		
		uint32_t min_cost = Kruskal(E, m);
		
		cout << total_cost - min_cost << endl;
		
		cin >> m >> n;
	}
}
