# hash_table_implementation

This is a program that reads in a file of integers and stores a key and value in a dynamically allocated array.
Radix sort is used to sort the array of structs in ascending order. A hash table is used as the lookup method for
finding a specific key in the array and its associated data. The hash table only contains the key, while the array
contains the key and its associated data, in this case it is simply an integer value that equals the key times ten.
The user is given a monitor message that states the status of the hash table, along with a menu of options
to choose. The user enters "1" to search for a specific key and get its associated data, "2" to print the sorted
array of structs to a text file, or "0" to exit the program. The user is alerted if their key is not found or
if they enter a menu value that is not valid.
