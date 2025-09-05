#ifndef EXTRACTMOVE_HPP
#define EXTRACTMOVE_HPP


#include <vector>
#include <utility>
#include <iostream>
#include <string>


class ExtractMove {
public:
  
    static bool match_pattern(const std::string& move);
    static std::vector<std::pair<int, int>> get_move(const std::string& move);
};

#endif