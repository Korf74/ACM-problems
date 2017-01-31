#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	size_t a, b;
	
	
	while(cin >> a >> b) {
		if(a > b) 
			cout << (a - b) << endl;
		else
			cout << (b - a) << endl;
	}
	
	return 0;
	
}
