#include <iostream> 
#include <fstream> 
#include <cmath>
#include <set>
#include <concepts> 

template <typename T> 
concept Numeric = std::is_arithmetic_v<T>; 

template <Numeric T> 
T count_fresh_ingredients(std::string filename) {
    T fresh_ingredients {};  
    std::string line {}; 
    std::ifstream file(filename); 
    std::set<T> fresh_ingredients_id; 
    if (!file) {
        std::cerr << "File not found" << "\n"; 
    }
    while (getline(file, line)) {
        // line will either be of the format num-num 
        // OR
        // num 
        if (line.find("-")) {
            size_t dash_pos = line.find("-"); 
            // we are still in the range section
            long long lower_bound {(long long)line.substr(line.begin(), line.begin() + std::find(line.begin(), line.end(), "-"))}; 
            long long upper_bound {(long long)line.substr(line.begin() + std::find(line.begin(), line.end(), "-"), line.end())}; 
            long long lower_bound {std::stoll}
            for (long long i {lower_bound} ; i <= upper_bound; ++i) {
                fresh_ingredients_id.insert(i); 
            }
        } else { // we are not in the range section anymore 
            if (fresh_ingredients_id.count(std::stoi(line))) {
                fresh_ingredients += 1; 
            } // else it doesn't exist in the set
        }
    }
    return fresh_ingredients; 
}

int main(int argc, char** argv) {
    std::string filename {argv[1]}; 
    std::cout << count_fresh_ingredients<long long>(filename) << "\n"; 
    return 0; 
}