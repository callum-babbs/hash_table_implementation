//Callum Babbs

#include "hashTable.h"
#include "radixSort.h"

int main(void) {
    std::ifstream inputFile; //creating file stream variable


    inputFile.open("keys.txt"); //opening file

    if (inputFile.fail()) { //error message for file
        std::cout << "Input file was not found. Program will terminate.\n";
        exit(1);
    }

    //code to get file size without reading in all the values
    inputFile.seekg(0, std::ios::end);
    int length = inputFile.tellg();
    length = length / 7;
    inputFile.seekg(0, std::ios::beg);

    data* myArray = new (std::nothrow) data[length + 1]; //creating array of structs

    //checks if memory allocation fails
    if (!myArray) {
        std::cout << "Memory allocation failed." << std::endl;
        exit(1);
    }

    int input;

    for (int k = 1; k < length + 1; k++) { //reads text file integers into array and creates associated value

        inputFile >> input;

        myArray[k].key = input;
        myArray[k].value = input * 10;

    }

    RadixSort(myArray, NumDigits, length);

    int hashSize = length * 1.2; //calculating size of hash table

    HashTable hash(hashSize); //creating hash table

    for (int i = 1; i < length + 1; i++) { //inserting key values and their index into hash table
        hash.insert(myArray[i].key, i);
    }

    hash.monitor();

    int userInput = 0;

    while (true) { //keeps looping menu until user decides to exit the program
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "==========================" << std::endl << std::endl;
        std::cout << "[1] : Look up value corresponding to any given key" << std::endl;
        std::cout << "[2] : Produce an output file of all the data in ascending order by key" << std::endl;
        std::cout << "[0] : Exit" << std::endl << std::endl;

        std::cin >> userInput;

        if (userInput == 0) {
            break;
        }
        else if (userInput == 1) {
            std::cout << std::endl << "Enter a value: ";
            std::cin >> userInput;
            int result = hash.lookup(userInput);
            if (result == -1) {
                std::cout << "\nNot found." << std::endl << std::endl << std::endl;
            }
            else {
                std::cout << "-----------";
                std::cout << "\nKey: " << myArray[result].key << "\nValue: " << myArray[result].value;
                std::cout << "\n-----------" << std::endl << std::endl;
            }
        }
        else if (userInput == 2) {
            std::ofstream outputFile;
            outputFile.open("output.txt");
            if (outputFile.fail()) { //error message for file
                std::cout << "Output file was not found. Program will terminate.\n";
                exit(1);
            }

            for (int i = 1; i < length + 1; i++) {
                outputFile << "[" << myArray[i].key << " , " << myArray[i].value << "]\n";
            }
            std::cout << std::endl << "Sorted array was printed to the file named output.txt" << std::endl << std::endl;
            outputFile.close();
        }
        else {
            std::cout << "\nPlease enter a valid choice." << std::endl << std::endl;
        }
    }
    inputFile.close();

    return 0;
}