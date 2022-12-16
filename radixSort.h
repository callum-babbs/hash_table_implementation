#ifndef radixSort_h
#define radixSort_h

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

const int NumDigits = 5; //default variable for the number of digits in each key

struct data { //struct that will be stored in dynamic array
	int key;
	int value;
};

//Given: the dynamic array of structs A, the number of digits in each key d, and the size of the file
//Task: implements radix sort to sort the array of structs in ascending order by key - uses counting sort within the function as
// its stable sort
//Return: a sorted array of structs, in ascending order
void RadixSort(data* A, int d, int fileSize);

//Given: the dynamic array of structs A, another dynamic array of structs B, the current digit being sorted, and the size of the file
//Task: implements counting sort - sorts array A into ascending order according to the digit indicated by the CurrentDigit parameter
//Return: array B, which contains the data from array B, but sorted into ascending order by the CurrentDigit
void CountingSort(data* A, data* B, int CurrentDigit, int fileSize);

#endif
