#include <vector>
#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '2';
        if(i < grid.size()-1 && grid[i+1][j] == '1'){
            dfs(grid, i+1, j);
        }
        if(i > 0 && grid[i-1][j] == '1') {
            dfs(grid, i-1, j);
        }
        if(j < grid[0].size() - 1 && grid[i][j+1] == '1') {
            dfs(grid, i, j+1);
        }
        if(j > 0 && grid[i][j-1] == '1') {
            dfs(grid, i, j-1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<char>> v =   {{'1','1','1'},
                                {'0','1','0'},
                                {'1','1','1'}};
    s.numIslands(v);
    return 0;
}
/*
[
['1','1','1'],
['0','1','0'],
['1','1','1']]
*/
