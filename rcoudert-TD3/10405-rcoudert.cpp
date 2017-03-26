#include <iostream>
#include <string>
#include <vector>

using namespace std;

// if two character are equal we add one and recursively check for i + 1, j + 1 else we return the max of both recursive checks for i + 1, j or i, j + 1
size_t compute(string& s1, string& s2, size_t i, size_t j, vector<vector<size_t> >& M) {
	if(M[i][j] != 0) return M[i][j];
	
	
	if(s1[i] == s2[j]) {
		
		if(i == s1.size() - 1 || j == s2.size() - 1) M[i][j] = 1;
		else M[i][j] = 1 + compute(s1, s2, i + 1, j + 1, M);
		
	} else {
				
		M[i][j] = max(
						i == s1.size() - 1 ? 0 : compute(s1, s2, i + 1, j, M),
						j == s2.size() - 1 ? 0 : compute(s1, s2, i, j + 1, M)
					);
	}
	
	return M[i][j];
}


int main() {
	
	string s1, s2;
	
	while(getline(cin, s1) && getline(cin, s2)) {
		
		//Dynamic programming, M[i][j] is the LCS of both strings starting at i and j respectively, i.e. we look for M[0][0]
		vector<vector<size_t> > M;
		
		for(size_t i = 0; i < s1.size(); i++) {
			M.push_back(vector<size_t>(s2.size(), 0));
		}
		
		cout << compute(s1, s2, 0, 0, M) << endl;
		
		
	}
	
	
	return 0;
}
