#include "hashTable.h"
#include "radixSort.h"

ListHead::ListHead(int k, int l) {
	this->k = k;
	this->l = l;
	this->n = NULL;
}

HashTable::HashTable(int b) {
	buckets = b;
	table = new ListHead * [buckets];

	for (int i = 0; i < buckets; i++)
		table[i] = NULL;
}

int HashTable::hashFunction(int key) {
	return (key % buckets);
}

void HashTable::insert(int k, int l) {
	int bucket = hashFunction(k);
	if (table[bucket] == NULL)
		table[bucket] = new ListHead(k, l);
	else {
		ListHead* en = table[bucket];
		while (en->n != NULL)
			en = en->n;
		if (en->k == k)
			en->l = l;
		else
			en->n = new ListHead(k, l);
	}
}

int HashTable::lookup(int k) {
	int bucket = hashFunction(k);
	if (table[bucket] == NULL)
		return -1;
	else {
		ListHead* en = table[bucket];
		while (en != NULL && en->k != k)
			en = en->n;
		if (en == NULL)
			return -1;
		else
			return en->l;
	}
}

void HashTable::monitor() {
	float count0 = 0.0, count1 = 0.0, count2 = 0.0, count3 = 0.0, count4 = 0.0, count5 = 0.0;
	for (int i = 0; i < buckets; i++) {
		if (table[i] == NULL)
			count0++;
		else {
			ListHead* en = table[i];
			int counter = 0;
			while (en != NULL) {
				en = en->n;
				counter++;
			}
			switch (counter) {
			case 1:
				count1++;
				break;
			case 2:
				count2++;
				break;
			case 3:
				count3++;
				break;
			case 4:
				count4++;
				break;
			case 5:
				count5++;
				break;
			}
		}
	}
	int longestList = 0;

	if (count5 != 0)
		longestList = 5;
	else if (count4 != 0)
		longestList = 4;
	else if (count3 != 0)
		longestList = 3;
	else if (count2 != 0)
		longestList = 2;
	else if (count1 != 1)
		longestList = 1;
	else
		longestList = 0;

	float percentage = (count1 + count2 + count3 + count4 + count5) / buckets;
	percentage = percentage * 100.0;

	std::cout << "Hash Table Monitor\n=================\n\n";
	std::cout << "Empty Location(s): " << count0 << std::endl;
	std::cout << "Location(s) with 1 item: " << count1 << std::endl;
	std::cout << "Location(s) with 2 items: " << count2 << std::endl;
	std::cout << "Location(s) with 3 items: " << count3 << std::endl;
	std::cout << "Location(s) with 4 items: " << count4 << std::endl;
	std::cout << "Location(s) with 5 items: " << count5 << std::endl;
	std::cout << "\nNumber of items on longest list: " << longestList << std::endl;
	std::cout << "Percent of locations with more than 0 items: " << std::setprecision(4) << percentage << "%" << std::endl << std::endl;

}

HashTable::~HashTable() {
	delete[] table;

	//for debugging
	//std::cout << "destructor executed..." << std::endl; 
}
