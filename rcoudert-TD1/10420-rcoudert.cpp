#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

int main() {
	
	map<string, int> conquests;
	
	int n;
	
	cin >> n;
	
	string country, woman;
	
	for(int i = 0; i < n; i++) {
		cin >> country;
		
		conquests[country] += 1;
		
		getline(cin, woman);
	}
	
	map<string, int>::iterator it;
	
	for(it = conquests.begin(); it != conquests.end(); it++) {
		cout << it -> first << " " << it -> second << endl;
	}
	
	return 0;
	
}
