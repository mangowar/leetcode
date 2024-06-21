#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isValidBox(int x, int y, vector<vector<char>>& board)
    {
        unordered_set<char> b;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[x+i][y+j] == '.')
                    continue;
                if(b.find(board[x+i][y+j]) == b.end())
                    b.insert(board[x+i][y+j]);
                else
                    return false;
            }
        }    
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> r;
        unordered_set<char> c;
        unordered_set<char> coords = {0, 3, 6};
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(coords.find(i) != coords.end() && coords.find(j) != coords.end())
                {
                    if(!isValidBox(i, j, board))
                        return false;
                }
                if(board[i][j] == '.')
                    continue;
                if(r.find(board[i][j] == r.end()))
                    r.insert(board[i][j]);
                else
                    return false;
            }
            r.clear();
        }
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] == '.')
                    continue;
                if(c.find(board[j][i]) == c.end())
                    c.insert(board[j][i]);
                else
                    return false;
            }
            c.clear();
        }
        return true;
    }
};
int main()
{
    return 0;
    Solution s;
}