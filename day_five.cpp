#include <iostream> 
#include <fstream> 
#include <cmath>
#include <set>
#include <vector> 
#include <concepts> 
#include <unordered_map>

template <typename T> 
concept Numeric = std::is_arithmetic_v<T>; 

template <Numeric T> 
T count_fresh_ingredients(const std::string& filename) {
    T fresh_ingredients {};  
    std::string line {}; 
    std::ifstream file(filename); 
    std::set<T> fresh_ingredients_id; 
    std::vector<T> bounds; 
    if (!file) {
        std::cerr << "File not found" << "\n"; 
    }
    while (getline(file, line)) {
        // line will either be of the format num-num 
        // OR
        // num 
        
        if (line.find("-") != std::string::npos) {
            //std::cout << line << "\n"; 
            size_t dash_pos{ line.find("-") }; 
            //auto iterator{ std::find(line.begin(), line.end(), line.begin(), "-") }; 
            //int distance{ std::distance(line, iterator) }; 
            // we are still in the range section
            long long lower_bound {std::stoll(line.substr(0, dash_pos))}; 
            long long upper_bound {std::stoll(line.substr(dash_pos + 1, line.length()))}; 
            //std::cout << "Lower bound: " << lower_bound << " | Upper bound: " << upper_bound << "\n"; 
            
            // for (long long i {lower_bound} ; i <= upper_bound; ++i) {
            //     // this takes too long
            //     std::cout << "Inserting" << i << "\n"; 
            //     fresh_ingredients_id.insert(i); 
            // }
            bounds.push_back(lower_bound); 
            bounds.push_back(upper_bound); 
        } 
        else if (line == "" || line == " ") {
            // the blankspace 
            continue; 
        } else { // we are not in the range section anymore 
            //std::cout << line << "\n"; 
            // if (fresh_ingredients_id.count(std::stoi(line))) {
            //     fresh_ingredients += 1; 
            // } // else it doesn't exist in the set
            for (size_t i{}; i < bounds.size(); i += 2) {   
                // increment by two because vector will always have even size because we store them as upper and lower pairs
                if (std::stoll(line) >= bounds[i] && std::stoll(line) <= bounds[i+1]) {
                    //std::cout << "Fresh: " << line << "\n"; 
                    fresh_ingredients += 1; 
                    break; 
                }
            }
        }
    }
    return fresh_ingredients; 
}

template <Numeric T> 
T get_total_fresh_ingredients(const std::string& filename) {
    std::ifstream infile(filename); 
    if (!infile) {
        std::cerr << "File not found" << "\n"; 
    }
    T total_fresh_ingredients{}; 
    T highest_bound{}; 
    T highest_lowest_bound{}; 
    std::vector<std::pair<T,T>> bounds; 
    std::string line; 
    while (getline(infile, line)) {
        if (line.find("-") != std::string::npos) {
            //std::cout << line << "\n"; 
            size_t dash_pos{ line.find("-") }; 

            long long lower_bound {std::stoll(line.substr(0, dash_pos))}; 
            long long upper_bound {std::stoll(line.substr(dash_pos + 1, line.length()))}; 
            std::cout << "Lower bound: " << lower_bound << " | Upper bound: " << upper_bound << "\n"; 
            
            for (size_t i{}; i < bounds.size(); ++i) { 
                if (lower_bound < bounds[i].first) {
                    if (upper_bound > bounds[i].second) {

                    } else {

                    }
                }
                else if (lower_bound > bounds[i].first) {
                    
                }
            }
            bounds[lower_bound] = upper_bound; 

        } 
    }
    return total_fresh_ingredients; 
}
int main(int argc, char** argv) {
    std::string filename {argv[1]}; 
    std::cout << count_fresh_ingredients<long long>(filename) << "\n"; 
    std::cout << get_total_fresh_ingredients<long long>(filename) << "\n"; 
    return 0; 
}