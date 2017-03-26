#include <iostream>
#include <stdint.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define LIMIT 500

class Vertex {
	
	public:
	
	Vertex* parent;
	uint32_t rank;
	float x;
	float y;
		
	Vertex() : parent(NULL), rank(0) {}
	
	Vertex(Vertex* p, uint32_t r) : parent(p), rank(r), x(0), y(0) {}
	
	Vertex(float _x, float _y) : parent(NULL), rank(0), x(_x), y(_y) {}
	
};

class UnionFind {
	
	private:
	
	
	public:
	
	UnionFind() {}
	
	void MakeSet(Vertex* v) {
		v -> parent = v;
		v -> rank = 0;
	}
	
	void Union(Vertex* u, Vertex* v) {
		Vertex* root_u = Find(u);
		Vertex* root_v = Find(v);
		
		if(root_u != root_v) {
			if(root_u -> rank < root_v -> rank) {
				root_u -> parent = root_v;
			} else {
				root_v -> parent = root_u;
				if(root_u -> rank == root_v -> rank) {
					++root_u -> rank;
				}
			}
		}
	}
	
	Vertex* Find(Vertex* u) {
		if(u -> parent != u) {
			u -> parent = Find(u -> parent);
		}
		
		return u -> parent;
	}
	
};

float dist(Vertex& v1, Vertex& v2) {
	float diff_x = v1.x - v2.x;
	float diff_y = v1.y - v2.y;
	
	return sqrt(diff_x * diff_x + diff_y * diff_y);
}

float Kruskal(uint32_t S, vector<pair<float, pair<Vertex*, Vertex*> > >& E, Vertex* V, uint32_t P) {
	
	uint32_t nb_edges = P - S;
	
	UnionFind UF;
	
	float D(0);
	
	for(uint32_t i = 0; i < P; ++i) {
		UF.MakeSet(V + i);
	}
		
	for(pair<float, pair<Vertex*, Vertex*> >& e : E) {
				
		if(nb_edges == 0) return D;
		
		Vertex* u = e.second.first;
		Vertex* v = e.second.second;
		
		if(UF.Find(u) != UF.Find(v)) {
			D = e.first;
			UF.Union(u, v);
			--nb_edges;
		}
		
	
	}
	
	return D;
	
}


bool edge_compare(pair<float, pair<Vertex*, Vertex*> >& e1, pair<float, pair<Vertex*, Vertex*> >& e2) {
	return e1.first < e2.first;
}

int main() {
	/*
	 * Algorithm : Run Kruskal's algorithm to find the min span tree but only for the |V| - S first edges
	 * the weights are the distances between vertices
	 * S is the number of possible satellite connections
	 */
	
	vector<pair<float, pair<Vertex*, Vertex*> > > E;
		
	uint32_t N(0), S(0), P(0);
	
	cin >> N;
	
	while(N-- > 0) {
		
		E.clear();
				
		cin >> S >> P;
		
		Vertex V[P];
				
		// Getting vertices positions
		for(uint32_t i = 0; i < P; ++i) {
			float x(0), y(0);
			cin >> x >> y;
			Vertex v(x, y);
			V[i] = v;
		}
		
		// Calculating the edges i.e. the distance between vertices
		for(uint32_t i = 0; i < P; ++i) {
			for(uint32_t j = i + 1; j < P; ++j) {
				pair<float, pair<Vertex*, Vertex*> > p;
				pair<Vertex*, Vertex*> e;
				Vertex* u = V + i;
				Vertex* v = V + j;
				
				e.first = u;
				e.second = v;
				p.first = dist(*u, *v);
				p.second = e;

				E.push_back(p);
			}
		}
		
		// sort the edges by weight for Kruskal
		sort(E.begin(), E.end(), edge_compare);
				
		printf("%.2f\n", Kruskal(S, E, V, P));
		
		
	}
}
