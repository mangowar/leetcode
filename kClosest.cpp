#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, greater<vector<int>>> dists;
        vector<vector<int>> res;
        for(int i = 0; i < points.size(); i++) {
            vector<int> buf;
            int x = points[i][0];
            int y = points[i][1];
            buf.push_back(x*x + y*y);
            buf.push_back(x);
            buf.push_back(y);
            dists.push(buf);
        }
        for(int i = 0; i < k; i++) {
            res.push_back({dists.top()[1], dists.top()[2]});
            dists.pop();
        }
        return res;
    }
};