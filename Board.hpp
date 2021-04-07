#include "Direction.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <map>
using namespace std;

namespace ariel{
    
    class Board{
        
        private:
        std::map<unsigned int, map <unsigned int, char>> b;
        public:
        Board();
        void post(unsigned int row,unsigned int column, enum Direction d,const std::string& s);
        string read(unsigned int row,unsigned int column , enum Direction d,unsigned int num);
        void show();
        ~Board();
    };
};