#include "Direction.hpp"
#include "Board.hpp"
#include <limits.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

namespace ariel {
        void Board::show(){
        for (unsigned int i = minRow; i <= maxRow; i++)
        {
            for (unsigned int j = minCol; j <= maxCol; j++)
            {
                if(board[i][j]!=0)
                    cout << board[i][j];
                else{
                cout<<'_';
            }
            }
           cout<<endl; 
        }        
    }

    string Board::read(unsigned int r, unsigned int c, Direction d, unsigned int l){
        string ans = "";
        if (d == Direction::Horizontal) {
            for (unsigned int i = 0; i < l; i++)
            {
                if(board[r][c+i]!=0)
                    ans += board[r][c+i];
                else
                ans+='_';
            }
        }
        if (d == Direction::Vertical) {
            for (unsigned int i = 0; i < l; i++)
            {
                if(board[r+i][c]!=0)
                    ans += board[r+i][c];
                else
                ans+='_';
            }
        }
        return ans;
    }

    void Board::post(unsigned int r, unsigned int c, Direction d, string s){
        if (d == Direction::Horizontal) {
                maxCol=max(c+unsigned(s.length()),maxCol);
                minCol=min(c,minCol);
                maxRow=max(r,maxRow);
                minRow=min(r,minRow);
                for (unsigned int i = 0; i < s.length(); i++)
                {
                    board[r][c + i] = s[i];
                }
        }
        if (d == Direction::Vertical) {
                maxRow=max(r+unsigned(s.length()),maxRow);
                minRow=min(r,minRow);
                maxCol=max(c,maxCol);
                minCol=min(c,minCol);
            
                for (unsigned int i = 0; i < s.length(); i++)
                {
                    board[r+i][c] = s[i];
                }
         }
        }
    


    Board::~Board(){}
}

