#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dists(mat.size(), vector<int>(mat[0].size(), -1));
        queue<pair<int, int>> points;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    dists[i][j] = 0;
                    points.push({i, j});
                }
            }
        }
        vector<pair<int, int>> sides = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!points.empty()) {
            int a = points.front().first;
            int b = points.front().second;
            points.pop();
            for(const auto& s: sides) {
                int i = a + s.first;             
                int j = b + s.second;
                if(i >= 0 && j >= 0 && i < n && j < m && dists[i][j] == -1) {
                    dists[i][j] = dists[a][b]+1;
                    points.push({i, j});
                }
            }
        }
        return dists;
    }
};