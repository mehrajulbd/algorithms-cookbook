#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

// ------------------------------------------------------------
// Global seed (initialized using current time)
// ------------------------------------------------------------
long long seed = time(0);

// ------------------------------------------------------------
// Function: manualRandom
// Purpose : Generate a pseudo-random number using math (LCG)
// ------------------------------------------------------------
int manualRandom(int min, int max)
{
    // Constants for Linear Congruential Generator
    const long long a = 1664525;
    const long long c = 1013904223;
    const long long m = 1e9 + 7;

    seed = (a * seed + c) % m;

    return min + (seed % (max - min + 1));
}

// ------------------------------------------------------------
// Function: generateRandomList
// Purpose : Generate a list of random numbers
// ------------------------------------------------------------
std::vector<int> generateRandomList(int size, int min, int max)
{
    std::vector<int> numbers;
    numbers.reserve(size);

    for (int i = 0; i < size; i++)
    {
        numbers.push_back(manualRandom(min, max));
    }

    return numbers;
}

// ------------------------------------------------------------
// Function: writeToFile
// Purpose : Write test cases to a file
// ------------------------------------------------------------
void writeToFile(const std::vector<int>& data, const std::string& filename)
{
    std::ofstream file(filename);

    if (!file)
    {
        std::cout << "Error opening file!\n";
        return;
    }

    for (int num : data)
    {
        file << num << "\n";
    }

    file.close();
    std::cout << "Test cases written to " << filename << std::endl;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------
int main()
{
    int size = 100;     // Number of test values
    int minValue = 1;
    int maxValue = 1000;

    std::vector<int> testCases = generateRandomList(size, minValue, maxValue);

    writeToFile(testCases, "test_cases.txt");

    return 0;
}
