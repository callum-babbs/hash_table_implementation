#ifndef hashTable_h
#define hashTable_h


class ListHead {
public:
	int k;
	int l;

	ListHead* n; //pointer member that points to the next value in the list

	//Given: the key value int k and the location value int l
	//Task: parameterized constructor that initializes the head of the list
	//Return: ListHead with initialized values that will store the key and the location, initialized next pointer 
	ListHead(int k, int l);

};


class HashTable {
private:
	ListHead** table;
	int buckets; //variable that will be the size of the hash table

public:

	//Given: size of the hash table "b"
	//Task: initializes the bucket variable and initializes the hash table, pointing all buckets to NULL
	//Return: initialized hash table and buckets value
	HashTable(int b);

	//Given: a key integer is passed in
	//Task: a hash function is performed on the key to determine which bucket the key is stored in
	//Return: the result of the hash function
	int hashFunction(int key);

	//Given: a key integer and a location integer - location is the index that the key integer is stored at in the array of structs
	//Task: the hash function is called with the key that is passed in, this gets the bucket that the key will be stored in. If the bucket points to NULL, then
	// it is empty, so a new listhead must be created that stores the key integer and the location integer. If the bucket does not point to NULL, then a pointer en
	// is created that points to the values already in the bucket and eventually creates a new ListHead that stores the new key and location integers within the bucket.
	//Return: nothing since it is void - but this function results in a new key and location integer being mapped/stored in a bucket
	void insert(int k, int l);

	//Given: a key integer given by the user
	//Task: uses the hash function to get the bucket that the key would be stored in. Then searches the hash table for the given key integer.
	//Return: returns -1 if the key is not found within the hash table. If the key is found, the l integer is returned, which is the index
	// of the key within the array of structs.
	int lookup(int k);

	//Given: the complete hash table with all the given keys stored within the table
	//Task: goes through the entire hash table and keeps track of the number of empty buckets, and the number of buckets that have 1-5 keys in the list. Also keeps track
	// of the bucket with the most keys (the longest list). Calculates the percent of buckets that have 1 or more keys stored.
	//Return: prints the number of buckets with 0,1,2,3,4,5 keys stored. Prints the bucket with the longest list. Prints the percent of buckets with 1 or more keys stored.
	void monitor(); //I set up this function as an attempt at extra credit

	//Destructor that deletes the hash table, deallocating memory
	~HashTable();
};

#endif
