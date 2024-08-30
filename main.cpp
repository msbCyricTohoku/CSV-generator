#include <iostream>
#include <fstream>
#include <random>

int main() {
    //define the number of columns and rows here
    const int num_columns = 10000;
    const int num_rows = 10000;

    //file name for the output CSV -- it will be overwritten
    std::ofstream csv_file("random_large_data.csv");

    //check if the file opened successfully
    if (!csv_file.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1;
    }

    //generate the column headers
    for (int i = 1; i <= num_columns; ++i) {
        csv_file << "Column_" << i;
        if (i != num_columns) {
            csv_file << ",";
        }
    }
    csv_file << "\n";

    //random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);

    //generate the rows of random data
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_columns; ++j) {
            csv_file << dis(gen);
            if (j != num_columns - 1) {
                csv_file << ",";
            }
        }
        csv_file << "\n";
    }

    //close the opened csv file
    csv_file.close();

    std::cout << "CSV file generated successfully!" << std::endl;

    return 0;
}

