#include "Direction.hpp"
#include <map>  
#include <limits.h>
#include <iostream>
#include <string>


using namespace std;

namespace ariel {
    class Board {
        unsigned int minRow;
        unsigned int minCol;
        unsigned int maxRow;
        unsigned int maxCol;
        map <unsigned int ,map<unsigned int,char>> board;

    public:
        Board() { 
        maxRow = 0;
        maxCol = 0;
        minRow = UINT_MAX;
        minCol = UINT_MAX;
}
        
        void post(unsigned int r, unsigned int c, Direction d, std::string s);

        std::string read(unsigned int r, unsigned int c, Direction d, unsigned int l);

        void show();

        ~Board();
    };
}
