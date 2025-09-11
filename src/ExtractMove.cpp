#include  "ExtractMove.hpp"
#include <regex>

  
     bool ExtractMove::match_pattern(const std::string& move) {
     
        std::regex move_pattern("^([a-h][1-8])\\s*--\\s*([a-h][1-8])$");
        std::smatch matches;

      
        if (std::regex_match(move, matches, move_pattern)) {

            if (matches[1] != matches[2]) {
                return true;
            }
        }
        return false;
    }

   
    std::vector<std::pair<int, int>> ExtractMove::get_move(const std::string& move) {
        std::regex move_pattern("^([a-h][1-8])\\s*--\\s*([a-h][1-8])$");
        std::smatch matches;

        
        if (std::regex_match(move, matches, move_pattern) && matches[1] != matches[2]) {
            std::string pre = matches[1].str();
            std::string post = matches[2].str();

           
            int row1 = pre[1] - '1'; 
            int col1 = pre[0] - 'a'; 

            int row2 = post[1] - '1';
            int col2 = post[0] - 'a';
            
           
            return {{row1, col1}, {row2, col2}};
        }

        
        return {};
    }


