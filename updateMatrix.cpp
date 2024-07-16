#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dists(mat.size(), vector<int>(mat[0].size(), __INT32_MAX__));
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    dists[i][j] = 0;
                    if(i > 0 && mat[i-1][j] == 1)
                        mat[i-1][j] = 1;
                    if(i < n-1 && mat[i+1][j] == 1)
                        mat[i+1][j] = 1;
                    if(j > 0 && mat[i][j-1] == 1)
                        mat[i][j-1] = 1;
                    if(j < m-1 && mat[i][j+1] == 1)
                        mat[i][j+1] = 1;
                    
                }
            }
        }
        
    }
};