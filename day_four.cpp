#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <bits/stdc++.h>

long long rolls_of_paper_accessed(std::string filename, [[maybe_unused]] char roll_of_paper, [[maybe_unused]] char non_roll_of_paper) {
    bool removed {true}; 
    long long rolls_of_paper{}; 
    std::string line {};
    std::vector<std::string> input;
    std::vector<char> buffer;    
    std::ifstream file(filename); 
    if (!file) {
        std::cerr << "File not found" << "\n"; 
    }
    // padding the input
    if (getline(file, line)) {
        std::string padding(line.length() + 2, '.');
        input.push_back(padding);
        //std::cout << padding << "\n";
        input.push_back("." + line + ".");
        //std::cout << "." + line + "." << "\n";
        while (getline(file, line)) {
            input.push_back("." + line + ".");
            //std::cout << "." + line + "." << "\n";
        }
        //std::cout << padding << "\n";
        input.push_back(padding);
    }
    while (removed) {
        // set removed before if statement (input[i][j] == roll_of_paper)
        // because if last roll of paper >= 4, the false even if earlier 
        // rolls of paper were removed. 
        removed = false;                                            
        for (int i{1}; i < (int)input.size() - 1; ++i) {
            for (int j{1}; j < (int)input[i].length() - 1; ++j) {
                // the 8 adjacent neighbours to a roll are 
                // [i-1][j-1] [i-1][j] [i-1][j+1]
                // [i]  [j-1] [i]  [j] [i]  [j+1]
                // [i+1][j-1] [i+1][j] [i+1][j+1]
                if (input[i][j] == roll_of_paper) {
                    buffer.push_back(input[i-1][j-1]);
                    //std::cout << input[i-1][j-1];
                    buffer.push_back(input[i-1][j]);
                    //std::cout << input[i-1][j];
                    buffer.push_back(input[i-1][j+1]);
                    //std::cout << input[i-1][j+1];
                    buffer.push_back(input[i][j-1]);
                    //std::cout << input[i][j-1];
                    buffer.push_back(input[i][j+1]);
                    //std::cout << input[i][j+1];
                    buffer.push_back(input[i+1][j-1]);
                    //std::cout << input[i+1][j-1];
                    buffer.push_back(input[i+1][j]);
                    //std::cout << input[i+1][j];
                    buffer.push_back(input[i+1][j+1]);
                    //std::cout << input[i+1][j+1] << "\n";
                    if (std::count(buffer.begin(), buffer.end(), roll_of_paper) < 4) {
                        rolls_of_paper += 1; 
                        input[i][j] = '.'; 
                        removed = true; 

                    }
                    buffer.clear(); 
                }
            }
        }
    }
    // for (const auto& row : input)  { 
    //     std::cout << row << "\n";
    // }
    return rolls_of_paper; 
}

int main(int argc, char** argv) {
    std::string filename {argv[1]};
    std::cout << rolls_of_paper_accessed(filename, '@', '.') << "\n";  
    return 0;
}