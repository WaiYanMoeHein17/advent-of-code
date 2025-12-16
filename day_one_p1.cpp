#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <cmath>

#define UPPER_LIMIT 100
#define LOWER_LIMIT 0

int clamp(int number) {
    if (number == 100) {
        return 0; 
    }
    else if (number > UPPER_LIMIT) {
        int multiplier = number / UPPER_LIMIT; 
        return number - (multiplier*UPPER_LIMIT); 
    } 
    else if (number < LOWER_LIMIT) {
        int multiplier = abs(number) / UPPER_LIMIT; 
        return (UPPER_LIMIT*(multiplier+1)) + number; 
    }
    return number; 
}

int rotate_right(int current, int amount) {
    /*if (clamp(current + amount) > 99 || clamp(current + amount) < 0) {
        std::cerr << "Something went wrong R " << amount << " | " << current << " Clamp " << clamp(current + amount) <<  std::endl; 
        throw 505; 
        return 0; 
    }
    return clamp(current + amount); */ 
    int total = current + amount; 
    int mult = total / UPPER_LIMIT; 
    int leftover = total - (mult * UPPER_LIMIT); 
    return LOWER_LIMIT + leftover; 
}

int rotate_left(int current, int amount) {
    /*if (clamp(current - amount) > 99 || clamp(current - amount) < 0) {
        std::cerr << "Something went wrong L " << amount << " | " << current << " Clamp " <<  clamp(current - amount) <<  std::endl; 
        throw 505; 
        return 0; 
    }
    return clamp(current - amount); */ 
    int total = current - amount; 
    if (total >= 0) {
        return total; 
    }
    int mult = abs(total) / UPPER_LIMIT; 
    int leftover = ((mult+1) * UPPER_LIMIT) - abs(total); 
    if (leftover == 100) {
        return 0;
    } else {
        return leftover; 
    }
}

int get_password(std::vector<std::string>& instructions) {
    int point_at_zero = 0; 
    int current = 50; 
    for (const auto& instruction : instructions) {
        if (instruction.substr(0,1).compare("L") != 0) {
            // means right 
            //std::cout << stoi(instruction.substr(1,instruction.length())) << std::endl; 
            current = rotate_right(current, stoi(instruction.substr(1,instruction.length()))); 
        } else {
            // means left
            //std::cout << stoi(instruction.substr(1,instruction.length())) << std::endl; 
            current = rotate_left(current, stoi(instruction.substr(1,instruction.length()))); 
        }
        std::cout << current << std::endl; 
        if (current == 0) {
            point_at_zero += 1; 
        }
    }
    return point_at_zero; 
}

int main(int argc, char** argv) {
    std::string filename = argv[1]; 
    std::ifstream ifs(filename); 
    if (!ifs) {
        std::cerr << "Couldn't open source for reading" << std::endl; 
    } 
    std::vector<std::string> instructions; 
    for (std::string instruction; ifs >> instruction;) {
        //std::cout << instruction << std::endl; 
        instructions.push_back(instruction); 
    }
    int ans = get_password(instructions); 
    std::cout << ans << std::endl; 

}