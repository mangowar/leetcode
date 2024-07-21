#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<set>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        set<vector<int>> oranges;
        vector<vector<int>> coords = {{1, 0}, {0 , 1}, {-1, 0}, {0, -1}};
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    oranges.insert({i, j});
                else if(grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }
        int count = 0;
        while(!rotten.empty()) {
            int sz = rotten.size();
            int flag = 0;
            for(int k = 0; k < sz; k++) {
                pair<int, int> curr = rotten.front();
                rotten.pop();
                for(auto i: coords) {
                    int a = curr.first + i[0];
                    int b = curr.second + i[1];
                    if(a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == 1) {
                        flag = 1;
                        rotten.push({a, b});
                        oranges.erase({a, b});
                        grid[a][b] = 2;
                    }
                }
            }
            if(flag) {
                count++;
            }
        }
        if(oranges.empty()) 
            return count;
        else   
            return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> o = {{2,1,1},{1,1,0},{0,1,1}};
    s.orangesRotting(o);
    return 0;
}