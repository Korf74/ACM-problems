#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// the first loop initializes, the second loop iterates over the decreasing sequences until there is no more i.e. we reached the LDS
int LDS(vector<size_t>& s) {
	
	if(s.size() <= 1) return s.size();
	
	vector<size_t> ans;
	
	for(size_t i = 0; i < s.size(); i++) {
		for(size_t j = i + 1; j < s.size(); j++) {
			if(s[j] <= s[i]) {
				ans.push_back(j);
			}
		}
	}
	
	
	int N = 1;
	
	while(ans.size() >= 1) {
		
		++N;
		
		vector<size_t> new_ans;
		
		for(size_t i = 0; i < ans.size(); i++) {
			for(size_t j = ans[i] + 1; j < s.size(); j++) {
				if(s[ans[i]] >= s[j]){
					
					new_ans.push_back(j);
				}
			}
		}
		
		ans = new_ans;
	}
	
	return N;
	
}


int main() {
	int a; 
	int pb = 1;
	
	while(cin >> a && a != -1) {
		
		if(pb > 1) cout << endl;
		
		vector<size_t> test;
		do {
			test.push_back(a);
			
		} while(cin >> a && a != -1);
				
			cout << "Test #" << pb << ":\n";
			cout << "  maximum possible interceptions: " << LDS(test) << endl; 
			
			pb ++;
	}
	
	return 0;
	
	
}






