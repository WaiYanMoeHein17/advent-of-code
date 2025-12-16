#include <iostream> 
#include <string>
#include <fstream> 
#include <sstream> 
#include <ostream>
#include <vector> 
#include <array> 
#include <cmath>

int find_biggest_two_voltage_in_line(std::string line) {
    int line_length { static_cast<int>(line.length()) }; 
    int first_digit {0}; 
    int second_digit {0}; 
    for (int i = 0; i < line_length; ++i) {
        if (line[i]-'0' > first_digit && i != line_length - 1) {
            //std::cout << "Line[i]: " << line[i] << "\n"; 
            first_digit = line[i]-'0'; 
            second_digit = 0; 
            //std::cout << "First Digit: " << first_digit << "\n"; 
        }
        else if (line[i]-'0' > second_digit) {
            second_digit = line[i]-'0'; 
            //std::cout << second_digit << "\n"; 
        }
    }
    //std::cout << first_digit * 10 + second_digit << "\n"; 
    return first_digit * 10 + second_digit;       
}

long long find_biggest_twelve_voltage_in_line(std::string line) {
    long long sum {}; 
    int line_length { static_cast<int>(line.length())}; 
    std::array<int, 12> twelve_digits{0,0,0,0,0,0,0,0,0,0,0,0}; 
    for (int i = 0; i < line_length; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (line[i]-'0' > twelve_digits[j] && i + (12 - j) <= line_length) {
                twelve_digits[j] = line[i]-'0'; 
                std::fill(twelve_digits.begin() + j + 1, twelve_digits.end(), 0); 
                break; 
            }
        }
    }
    for (int i = 11; i >= 0; i--) {
        sum += twelve_digits[11-i] * std::pow(10,i); 
    }
    std::cout << sum << "\n"; 
    return sum; 
}

long long output_joltage(std::string filename) {
    long long sum {0};
    std::string line {}; 
    std::ifstream file(filename); 
    while (getline(file, line)) {
        //std::cout << line << "\n"; 
        //sum += find_biggest_two_voltage_in_line(line); 
        sum += find_biggest_twelve_voltage_in_line(line); 
        //std::cout << sum << "\n"; 
    }
    return sum; 
}

int main(int argc, char** argv) {
    std::string filename = argv[1]; 
    std::cout << output_joltage(filename) << "\n"; 
}