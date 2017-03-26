#include <string.h>
#include <vector>
#include <stdint.h>
#include <iostream>

using namespace std;

class Vertex {
	
	public:
	
	uint32_t d;
	Vertex* pred;
	
	Vertex() : d(-1), pred(NULL) {}
	
};

void relax(pair<Vertex*, Vertex*>& e) {
	Vertex* u = e.first;
	Vertex* v = e.second;
	uint32_t w = 1;
	
	if((u -> d != (uint32_t)-1) && v -> d > u -> d + w) {
		v -> d = u -> d + w;
		v -> pred = u;
	}
}

void B_F(vector<pair<Vertex*, Vertex*> >& edges, Vertex V[100]) {
	
	// loop |V| - 1 times (no cycle)
	for(uint32_t i = 1; i < 100; ++i) {
		for(pair<Vertex*, Vertex*> e : edges) {
			relax(e);
		}
	}
	
}

void init_source(uint32_t u, Vertex V[100]) {
	for(uint32_t i = 0; i < 100; ++i) {
		if(i != u) V[i].d = -1;
		else V[i].d = 0;
		V[i].pred = NULL;
	}
}

int main() {
	/*
	 * Algorithm : Run shortest path algorithm (Belmond-ford here) for all vertices, add all distances and normalize
	 */
	
	vector<pair<Vertex*, Vertex*> > E;
	Vertex V[100];
	bool in_graph[100];
	for(uint32_t i = 0; i < 100; ++i) {
		Vertex v;
		V[i] = v;
	}
	
	uint32_t a, b;
	
	cin >> a >> b;
	
	uint32_t t_case(1);
	
	while(a != 0 || b != 0) {
		
		E.clear();
		
		for(uint32_t i = 0; i < 100; ++i) {
			in_graph[i] = false;
		}
		
		while(a!= 0 || b != 0) {
			in_graph[a - 1] = true;
			in_graph[b - 1] = true;
			
			pair<Vertex*, Vertex*> p;
			p.first = &V[b - 1];
			p.second = &V[a - 1];
			
			E.push_back(p);
			
			cin >> a >> b;
		}
		
		uint32_t nb_vertex(0);
		for(bool b : in_graph) {
			if(b) ++nb_vertex;
		}
		
		uint32_t sum(0);
		
		for(uint32_t i = 0; i < 100; ++i) {
			init_source(i, V);
			B_F(E, V);

			for(Vertex v : V) {
				if(v.d != (uint32_t)-1) sum += v.d;
			}
		}
		
		double ans = (double)sum / (nb_vertex * (nb_vertex - 1));
		
		printf("Case %u: average length between pages = %.3f clicks\n", t_case, ans);
		
		cin >> a >> b;
		
		++t_case;
	}
	
}
