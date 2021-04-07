#include "Board.hpp"
#include <iostream>
#include <string>
#include <array>
#include <limits.h>
#include <stdexcept>
#include <map>
using namespace std;

namespace ariel{
  
    unsigned int max_colums;
    unsigned int min_colums;
    unsigned int max_row;
    unsigned int min_row;
    
    
    Board::Board(){
        min_row = INT_MAX;
        max_row = 0;
        min_colums = INT_MAX;
        max_colums = 0;
    }
  
    void Board::post(unsigned int row, unsigned int column, enum Direction d, const string &s){
           if (d == Direction::Horizontal){
            for(unsigned int i=0; i<s.length(); i++){
                b[row][column + i] = s[i];
            }
            min_row = min(min_row,row);
            max_row = max(max_row,row);
            min_colums = min(min_colums,column);
            max_colums = max((column + unsigned(s.length())), max_colums);
        }
        else
        {
            for(unsigned int i=0; i<s.length(); i++)
            {
                b[row + i][column] = s[i];
            }  
            min_row = min(min_row,row);
            max_row = max((row + unsigned(s.length())), max_row);
            min_colums = min(min_colums,column);
            max_colums = max(min_colums,column);
        }
        
    }
    string Board::read(unsigned int row, unsigned int column , enum Direction d, unsigned int num){
        string ans;
        for(unsigned int i=0; i<num; i++)
        {
            if (d == Direction::Horizontal)
            {
                
                if(b[row][column+i] == 0)
                {
                    ans += "_";
                }
                else
                {
                    ans += b[row][column+i];
                }
            }
            else
            {
                if(b[row+i][column] == 0)
                {
                    ans += "_";
                }
                else
                {
                    ans += b[row+i][column];
                }
            }
        }
        return ans;
    }
    void Board::show(){
    unsigned int display_rows = (max_row - min_row) + 1;
    unsigned int display_cols = (max_colums - min_colums);
    
        for(unsigned int i = 0; i<display_rows; i++)  {
            for(unsigned int j = 0; j<display_cols; j++)
            {
                if(b[i][j] != 0)
                {
                    cout << b[i][j];
                }
                else
                {
                    cout << "_";
                }
                
            }
            cout << endl;
        }
    }
    Board::~Board(){

    }
}