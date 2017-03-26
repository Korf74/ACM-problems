#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	char c;
	bool left = true;
	
	cin >> noskipws;
	
	while(cin >> c) {
		if(c == '"') {
			if(left) {
				cout << '`' << '`';
			} else {
				cout << '\'' << '\'';
			}
			left = !left;
		} else {
			cout << c;
		}
	}
	
	return 0;
	
}
