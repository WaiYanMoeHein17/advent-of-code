#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <utility>
#include <cstdlib> 

// perhaps we can group into two categories,
// 1. additions
// 2. multiplications
// then we can utilise simd 
// if we can read from bottom up on the file
// then we can know which struct the values 
// will go into.

struct SoA {
    std::vector<long long> a;                   // x1
    std::vector<long long> b;                   // x2
    std::vector<long long> c;                   // x3
    std::vector<long long> d;                   // x4
    std::vector<std::string> operation;         // operation
    std::vector<long long> answer;              // answer
}; 

template <typename T> 
concept Numeric = std::is_arithmetic_v<T>; 

// can I make this so the vector<T> using template, but stoll, stoi, stof... ? 
template <typename T> 
std::vector<T> extract_words_from_line(std::string line) {
    std::vector<T> numbers_in_line;
    size_t start{}; 
    
    for (size_t end{}; end <= line.length(); ++end) {
        if (end == line.length() || line[end] == ' ') {
            if (end > start) {  // Only add non-empty strings
                std::string word = line.substr(start, end - start);
                if (!word.empty() && word != " ") {
                    numbers_in_line.push_back(word);
                }
            }
            start = end + 1;
        }
    }
    
    
    return numbers_in_line; 
}

long long calculate_column(const SoA &soa) {
    long long total{}; 
    for (size_t i{}; i < soa.a.size(); ++i) {
        auto operation{ soa.operation[i] }; 
        if (operation == "+") {
            total += soa.a[i] + soa.b[i] + soa.c[i] + soa.d[i]; 
        } else {
            total += soa.a[i] * soa.b[i] * soa.c[i] * soa.d[i]; 
        }
        //std::cout << total << "\n";
    }
    return total; 
}

long long calculate_worksheet(const std::string& filename) {
    std::ifstream infile(filename); 
    if (!infile) {
        std::cerr << "File not found" << "\n"; 
    }
    std::string line{}; 
    SoA soa; 
    int line_count{}; 
    while(getline(infile,line)) {
        long long current{}; 
        long long count{}; 
        std::vector<std::string> numbers = extract_words_from_line<std::string>(line); 
        std::cout << line << "\n"; 
        std::cout << numbers.size() << "\n"; 
        for (size_t i{}; i < numbers.size(); ++i) {

            std::cout << "Count: " << line_count << "\n"; 
            switch (line_count) {
            case 0:
                soa.a.push_back(std::stoll(numbers[i])); 
                break;
            case 1: 
                soa.b.push_back(std::stoll(numbers[i])); 
                break; 
            case 2: 
                soa.c.push_back(std::stoll(numbers[i])); 
                break;
            case 3: 
                soa.d.push_back(std::stoll(numbers[i])); 
                break; 
            case 4: 
                soa.operation.push_back(numbers[i]); 
                break; 
            default:
                std::cout << "Went to default" << "\n"; 
                break;
            }
        }
        count += 1; 
        line_count += 1; 
    }
    return calculate_column(soa); 
}

int main(int argc, char** argv) {
    std::string filename = argv[1]; 
    std::cout << calculate_worksheet(filename) << "\n"; 
    return EXIT_SUCCESS;  
}