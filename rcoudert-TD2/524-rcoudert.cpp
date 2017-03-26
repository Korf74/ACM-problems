#include <iostream>
#include <map>
#include <vector>
#include <math.h>

using namespace std;


bool isPrime(int a) {
	for(int i = 2; i < a; i++) {
		if(a % i == 0) return false;
	}
	
	return true;
}

// This functions finds all children for a, i is a children of a if i != a and i+a is prime
vector<int> find_possible_neighbours(int a, int n) {
	vector<int> v;
	for(int i = 1; i <= n; i++) {
		if(i != a && isPrime(i + a)) v.push_back(i);
	}
	
	return v;
	
}

// This function checks wether a has 1 in its children
bool has_child_1(map<int, vector<int> > g, int a) {
	for(size_t i = 0; i < g[a].size(); i++) {
		if(g[a][i] == 1) return true;
	}
	
	return false;
}

// a simple contains function
bool contains(vector<int> v, int x) {
	for(size_t i = 0; i < v.size(); i++) {
		if(v[i] == x) return true;
	}
	
	return false;
}

// DFS traversal
void DFS_rec(map<int, vector<int> > g, vector<int> curr_path, vector<vector<int> >& ans, int current, int n) {

	
	curr_path.push_back(current);
	
	// if we reached max possible path length, either we found a solution, either we search elsewehere (return to parent)
	if(curr_path.size() == (unsigned int)n) {
		if(has_child_1(g, current)) {
			vector<int> path_copy(curr_path);
			ans.push_back(path_copy);
		}
		
		return;
	}
	
	
	
	vector<int> children = g[current];
	
	// recursive call
	for(size_t i = 0; i < children.size(); i++) {
		if(!contains(curr_path, children[i])) DFS_rec(g, curr_path, ans, children[i], n);
	}
	
	curr_path.pop_back();
		
	
	
	
}

// DFS traversal init
vector<vector<int> > DFS(map<int, vector<int> > g, int n) {

	
	vector<vector<int> > ans;
	
	if(n == 1) {
		ans.push_back(vector<int>(1, 1));
		return ans;
	}
	
	vector<int> path;

	DFS_rec(g, path, ans, 1, n);
	
	return ans;
}


int main() {
	int n;
	int pb = 1;
	
	while(cin >> n) {
		
		// for output format reasons
		if(pb != 1) cout << endl;
		
		
		//getting input
		map<int, vector<int> > g;

		for(int i = 1; i <= n; i++) {
			g[i] = find_possible_neighbours(i, n);
		}
		
			
		//computing and outputing
		vector<vector<int> > ans = DFS(g, n);

		cout << "Case " << pb << ":\n";

		for(size_t i = 0; i < ans.size(); i++) {
			cout << ans[i][0];
			for(int j = 1; j < n; j ++) {
				cout << " ";
				cout << ans[i][j];
			}
			cout << endl;
		}
		
		pb ++;
		
	}
	
	return 0;
	
}
