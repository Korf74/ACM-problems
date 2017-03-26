#include <stdint.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define LIMIT 100

class Vertex {
	
	public:
	
	uint32_t d;
	Vertex* pred;
	
	Vertex() : d(-1), pred(NULL) {}
	
};

void relax(pair<uint32_t, pair<Vertex*, Vertex*> >& e) {
	Vertex* u = e.second.first;
	Vertex* v = e.second.second;
	uint32_t w = e.first;
	
	if((u -> d != (uint32_t)-1) && v -> d > u -> d + w) {
		v -> d = u -> d + w;
		v -> pred = u;
	}
}

void B_F(vector<pair<uint32_t, pair<Vertex*, Vertex*> > >& edges, vector<Vertex>& V) {
	
	// loop |V| - 1 times (no need to check for cycles)
	for(uint32_t i = 1; i < V.size(); ++i) {
		for(pair<uint32_t, pair<Vertex*, Vertex*> > e : edges) {
			relax(e);
		}
	}
	
}

int main() {
	/*
	 * Algorithm : Simply use Belmond-Ford and check how many vertices have distance required by T 
	 */
	
	uint32_t pb(0);
	uint32_t N(0), E(0), T(0), M(0);
	
	vector<pair<uint32_t, pair<Vertex*, Vertex*> > > edges;
	vector<Vertex> V;
	
	cin >> pb;
	
	while(pb-- > 0) {
		
		edges.clear();
		V.clear();
		
		cin >> N >> E >> T >> M;
		
		for(uint32_t i = 1; i <= N; ++i) {
			Vertex v;
			V.push_back(v);
		}
				
		uint32_t a, b, c;
		
		for(uint32_t i = 1; i <= M; ++i) {
			cin >> a >> b >> c;
			pair<Vertex*, Vertex*> e;
			pair<uint32_t, pair<Vertex*, Vertex*> > p;
			
			// invert edges to use single source shortest path algorithm
			e.first = &V[b - 1];
			e.second = &V[a - 1];
			
			p.first = c;
			p.second = e;
			
			edges.push_back(p);
		}
				
		// init source
		V[E - 1].d = 0;
				
		B_F(edges, V);
		
		uint32_t ans(0);
		
		for(Vertex v : V) {
			if(v.d <= T) ++ ans;
		}
		
		cout << ans << endl;
		
		if(pb > 0) cout << endl;
	}

}
