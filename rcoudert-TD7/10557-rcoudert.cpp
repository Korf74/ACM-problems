#include <stdint.h>
#include <iostream>
#include <vector>

using namespace std;

class Vertex {
	
	public:
	
	int32_t d;
	int32_t energy;
	bool infinite_distance;
	bool is_end;
	bool visited;
	Vertex* pred;
	vector<Vertex*> neighbours;
	
	Vertex() : d(-1), energy(0), infinite_distance(true), is_end(false), visited(false), pred(NULL) {}
	
};

void relax(pair<int32_t, pair<Vertex*, Vertex*> >& e) {
	Vertex* u = e.second.first;
	Vertex* v = e.second.second;
	int32_t w = e.first;
	
	if((v -> infinite_distance) || v -> d < u -> d + w) {
		v -> d = u -> d + w;
		v -> pred = u;
		v -> infinite_distance = false;
	}
}

bool is_connected_to_end(Vertex* u, vector<Vertex>& V) {
	if(u -> is_end) return true;
	
	u -> visited = true;
	
	for(Vertex* v : u -> neighbours) {
		if(!v -> visited) {
			if(is_connected_to_end(v, V)) return true;
		}
	}
	
	return false;
}

bool B_F(vector<pair<int32_t, pair<Vertex*, Vertex*> > >& edges, vector<Vertex>& V, uint32_t n) {
		
	// loop |V| - 1 times
	for(uint32_t i = 1; i < n; ++i) {
		for(pair<int32_t, pair<Vertex*, Vertex*> > e : edges) {
			// don't relax if we reached 0 energy
			if(e.second.first -> d > 0) {
				relax(e);
			}
		}
		
	}
			
		
	// loop 1 more time again to detect where are positive cycles if there is any
	for(pair<int32_t, pair<Vertex*, Vertex*> > e : edges) {
		if(e.second.first -> d > 0) {
			Vertex* u = e.second.first;
			Vertex* v = e.second.second;
			int32_t w = e.first;
			
			for(uint32_t i = 0; i < n; ++i) V[i].visited = false;
						
			// if there's a positive cycle connected to the end we're done
			if(((v -> infinite_distance || v -> d < u -> d + w) && is_connected_to_end(v, V))) return true;
		}
	}

	// if there's no cycle we just need to check if the energy at the end is positive
	if((!V[n - 1].infinite_distance && V[n - 1].d > 0)) return true;
	
	return false;
		
}

int main() {
	/*
	 * Algorithm : run belmond-ford with energy as edge weights, the game is winnable if either :
	 * 	- The biggest path from the source to all vertices that lead to destination are > 0 and never goes under 0
	 * 	- There exists a positive cycle connected to the end
	 */
	
	vector<pair<int32_t, pair<Vertex*, Vertex*> > > E;
	vector<Vertex> V;
	
	for(uint32_t i = 0; i < 100; ++i) {
		Vertex v;
		vector<Vertex*> vec;
		v.neighbours = vec;
		V.push_back(v);
	}
	
	int32_t n(0);
	
	cin >> n;
	
	while(n >= 0) {
		
		E.clear();
		
		// Vertex initialization
		for(uint32_t i = 0; i < 100; ++i) {
			Vertex v;
			vector<Vertex*> vec;
			v.neighbours = vec;
			V[i] = v;
		}
		
		int32_t energy(0);
		uint32_t out_degree(0);
		
		// input
		for(int32_t i = 0; i < n; ++i) {
			cin >> energy;
			cin >> out_degree;
			
			V[i].energy = energy;
			
			uint32_t v(0);
						
			for(uint32_t j = 0; j < out_degree; ++j) {
				pair<int32_t, pair<Vertex*, Vertex*> > e;
				pair<Vertex*, Vertex*> p;
				
				cin >> v;
				
				p.first = &V[i];
				p.second =  &V[v - 1];
				
				V[i].neighbours.push_back(&V[v - 1]);
				
				e.second = p;
				
				E.push_back(e);
			}
		}
		
		// Put vertex energies on edges
		for(uint32_t i = 0; i < E.size(); ++i) {
			pair<int32_t, pair<Vertex*, Vertex*> > e = E[i];
			e.first = e.second.second -> energy;
			E[i] = e;
		}
		
		// init source and end
		V[0].d = 100;
		V[0].infinite_distance = false; 
		V[n - 1].is_end = true;
		
		bool ans = B_F(E, V, n);
		
		if(ans) {
			cout << "winnable" << endl;
		} else {
			cout << "hopeless" << endl;
		}
		
		cin >> n;
	}
	
}
