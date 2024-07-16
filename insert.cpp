#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0; 
        for(int i = 0; i < intervals.size(); i++) {
            if(newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                auto it = next(intervals.begin(), i);
                res.insert(res.end(), it, intervals.end());
                return res;
            }
            else if(intervals[i][1] < newInterval[0])
                res.push_back(intervals[i]);
            else if(intervals[i][0] <= newInterval[1] && newInterval[0] <= intervals[i][1]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{-5, -3}, {1, 3}, {6, 9}, {15, 20}};
                            // {2, 5}
    int a, b;
    cin >> a >> b;
    vector<int> NewInt = {a, b};
    s.insert(intervals, NewInt);
    return 0;
}

/* 
[[1,3],[6,9]]
[10,12]

---   ----
  ------

*/
