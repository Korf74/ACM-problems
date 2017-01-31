#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
	size_t participants, budget, hotels, weeks;
	size_t cost;
	
	//main loop
	while(cin >> participants >> budget >> hotels >> weeks) {
		
		// the initial cost is over the budget, it will be lowered if a solution is found
		cost = budget + 1;
						
		size_t hotel_price;
		size_t hotel_beds;
		
		for(size_t i = 0; i < hotels; i++) {
			cin >> hotel_price;
			size_t hotel_cost = hotel_price * participants;
			
				if(hotel_cost <= budget) {
					
					
					for(size_t j = 0; j < weeks; j++) { // check for lowest price amongst possible weeks if it exists
						
						cin >> hotel_beds;
						
						if(hotel_beds >= participants) { // enough place
							cost = min(cost, hotel_cost);
						}
					}
				} else {
					string dump;
					cin.ignore();
					getline(cin, dump);
				}
		}
		
		if(cost > budget) {
			cout << "stay home" << endl;
		} else {
			cout << cost << endl;
		}
	}
	
	return 0;
	
}

