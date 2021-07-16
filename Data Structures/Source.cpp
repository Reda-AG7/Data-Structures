#include "HashTable.h"

int main() {
	std::unordered_set<int> mySet = { 14,4, 666, 6666, 106, 22222, 2222, 17, 50, 20 };
	HT ht(mySet);

	ht.displayHT();
	ht.search(20);

	return 0;
}
