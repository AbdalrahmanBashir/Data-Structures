// HashFunction-String.cpp
// Read strings from a file, hash them into a fixed-size table,
// and display intermediate hash values along with collisions.

// Uses a simple polynomial rolling hash 
// Table size is 389 a prime number to reduce collisions.
// Tracks the number of strings per hash slot 
// and stores the last string in each slot.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// Computes a hash for a given string and maps it to a table index.
unsigned int hashString(const std::string& key, int tableSize)
{
    unsigned int hashVal = 0;
    // Print the intermediate hash value at each character setp.
    std::cout << std::endl;
    for (char ch: key)
    {
       // Polynomial rolling hash.
       hashVal = 37 * hashVal + ch;
       std::cout << hashVal << " ";
    }
    std::cout << std::endl;
  
    // Map the potentially large hash value into the table size.
    return hashVal % tableSize;
}

int main()
{
    const int ARRAY_SIZE = 389;        // Size of the hash table
    int keyCnt[ARRAY_SIZE];            // Count of strings hashed into each slot.
    std::string strHold[ARRAY_SIZE];   // Last string stored in each slot.

    std::ifstream inputData;
    std::string inputStr;
    int hashKey;
    int cnt =0;                        // Total number of strings processed.


    // Initialize the hash table counters and string storage
    for(int i=0; i < ARRAY_SIZE; i++)
    {
        keyCnt[i] = 0;
        strHold[i] = "";
    }

    // Open input file
    inputData.open("StringListRandom.txt");
    if(!inputData)
    {
       std::cout << std::endl << "Input file not found." << std::endl << std::endl;
       return -1;
    }

    // Read strings one by one and hash them
    while (inputData >> inputStr)
    {

    // Compute hash index for the current string
       hashKey = hashString(inputStr, ARRAY_SIZE);

    // Increment the counter for this slot
       keyCnt[hashKey] +=1;

    // Store the last string in this slot
       strHold[hashKey] = inputStr;

       std::cout << std::endl << std::setw(2) << keyCnt[hashKey] 
                 << " " << std::setw(5) << hashKey 
                        <<  "  " << inputStr;
       cnt++;
    }

    inputData.close();

    // Summary: total number of strings processed
    std::cout << std::endl << std::endl << std::setw(9) 
              << cnt << "   strings hashed."  << std::endl;
    std::cout << std::endl;
    return 0;
}
