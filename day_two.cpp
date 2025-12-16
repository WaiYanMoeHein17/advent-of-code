#include <iostream> 
#include <fstream> 
#include <map> 
#include <unordered_map> 
#include <regex>
#include <vector> 
#include <string> 
#include <algorithm>
//#include <bits/stdc++.h>

long long find_invalid_ids(std::string filename) {
    std::ifstream file(filename); 
    std::string line; 
    std::regex pattern(R"((\d+)-(\d+))"); 
    //std::vector<long long> invalid_ids; 
    long long sum {}; 
    
    while (getline(file, line)) {
        auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto end = std::sregex_iterator();
        
        for (auto it = begin; it != end; ++it) {
            std::smatch match = *it;
            long long lower_bound_int = std::stoll(match[1]);
            long long upper_bound_int = std::stoll(match[2]);
            std::cout << "Upper bound: " << upper_bound_int << " || Lower Bound: " << lower_bound_int << "\n"; 
            for (long long i = lower_bound_int; i <= upper_bound_int; ++i) {
                //std::cout << i << "\n"; 
                std::string number = std::to_string(i); 
                int mid_point = number.length() / 2; 
                if (number.substr(0, mid_point) == number.substr(mid_point, number.length())) {
                    //invalid_ids.push_back(std::stoll(number)); 
                    std::cout << "Number: " << number << "\n"; 
                    sum += std::stoll(number); 
                }
            }
        }
        //break; 
    }
    return sum; 
    //return std::accumulate(invalid_ids.begin(), invalid_ids.end(), 0); 
}

long long find_invalid_ids_at_least_twice(std::string filename) {
    std::ifstream file(filename); 
    std::string line {}; 
    std::regex pattern(R"((\d+)-(\d+))"); 
    long long sum {}; 
    if (!file) {
        std::cerr << "File not found" << "\n"; 
    }

    while (getline(file, line)) {
        auto begin {std::sregex_iterator(line.begin(), line.end(), pattern)};
        auto end {std::sregex_iterator()};
        for (auto it {begin}; it != end; ++it) {
            std::smatch match {*it};
            long long lower_bound_int {std::stoll(match[1])};
            long long upper_bound_int {std::stoll(match[2])};
            for (long long i{lower_bound_int}; i < upper_bound_int; ++i) {
                std::string number = std::to_string(i); 
                for (auto j{0uz}; j < number.length(); ++j) {
                    if () {
                        sum += ; 
                    }
                }
            }
        }
    }
    return sum; 
}

int main (int argc, char** argv) {
    std::string filename = argv[1];
    std::cout << find_invalid_ids(filename) << "\n"; 
}