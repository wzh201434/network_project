#include "block_deque.h"
#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> splitStr(const std::string &s, char delim) {
    std::vector<std::string> res;
    size_t start = 0, pos = s.find(delim);
    while (pos != std::string::npos) {
        res.push_back(s.substr(start, pos - start));
        start = pos + 1;
        pos = s.find(delim, start);
    }
    res.push_back(s.substr(start));
    return res;
}
int main() {
    BlockDeque bd;
    std::string line;
    while (getline(std::cin, line)) {
        std::vector<std::string> tokens = splitStr(line, ' ');
        if (tokens[0] == "push") {
            bd.push(stoi(tokens[1]));
        } else if (tokens[0] == "pop") {
            auto value = bd.pop();
            if (value.has_value()) {
                std::cout << value.value() << std::endl;
            } else {
                std::cout << "empty" << std::endl;
            }
        }
    }
}