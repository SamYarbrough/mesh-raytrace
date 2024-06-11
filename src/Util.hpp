#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

namespace Util {
    // split string with delimiter
    std::vector<std::string> split(std::string, std::string);

    // not enough tokens in line in file
    void insufTokens(std::string, std::string);

    // truncate decimals to num, return string
    std::string trunc(float, int);
};

std::vector<std::string> Util::split(std::string str, std::string delim) {
    std::vector<std::string> s = std::vector<std::string>();

    int delim_len = delim.length();

    int last = 0; int next = 0;
    while ((next = str.find(delim, last)) != std::string::npos) {
        s.push_back(str.substr(last, next-last));
        last = next + 1;
    }
    s.push_back(str.substr(last));

    return s;
}

void Util::insufTokens(std::string filepath, std::string line) {
    std::cerr << "Unexpected input while loading \"" << filepath << "\":\n";
    std::cerr << "Insufficient tokens.\n";
    std::cerr << "    " << line << "\n";
}

std::string Util::trunc(float val, int decimals) {
    std::string tmp = std::to_string(val);
    int ind = tmp.find(".");
    return tmp.substr(0, std::min(ind + decimals + 1, (int)(tmp.size()-1)));
}
