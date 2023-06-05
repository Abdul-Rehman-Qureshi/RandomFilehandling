#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void generateRandomNumbers(const std::string& filename, int count) {
    std::ofstream file(filename);

    if (!file) {
        std::cout << "Error creating file: " << filename << std::endl;
        return;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < count; ++i) {
        int randomNumber = std::rand();
        file << randomNumber << std::endl;
    }

    file.close();
    std::cout << "Random numbers generated and saved to file: " << filename << std::endl;
}

void readRandomNumbers(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    int number;
    while (file >> number) {
        std::cout << number << " ";
    }

    file.close();
    std::cout << std::endl;
}

int main() {
    const std::string filename = "random_numbers.txt";
    int count = 10;

    // Generate and save random numbers to file
    generateRandomNumbers(filename, count);

    // Read and display random numbers from file
    readRandomNumbers(filename);

    return 0;
}

