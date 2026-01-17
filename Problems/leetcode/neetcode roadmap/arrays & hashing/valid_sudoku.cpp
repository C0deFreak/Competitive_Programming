#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool columns[9][9] = {false};
        bool boxes[9][9] = {false};

        int rn;

        for(int y=0; y<9; y++)
        for(int x=0; x<9; x++) {

            if(board[y][x] == '.') continue;
            
            // ako želiš acii vrijednost to je samo int(char), a da char -> int to je int val = char - '0'
            rn = board[y][x]-'1';
            if(rows[y][rn] || columns[x][rn] || boxes[int((y/3)*3+x/3)][rn]) return false;

            rows[y][rn] = true;
            columns[x][rn] = true;
            // int(x/y) == x//y
            boxes[int((y/3)*3+x/3)][rn] = true;
            
        }
        return true;
    }
};