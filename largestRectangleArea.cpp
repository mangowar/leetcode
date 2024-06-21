/* [4,2,0,3,2,5,0,1] */

#include<vector>
#include<stack>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        /* pair: index, hight */
        stack<pair<int, int>> buf; 
        for(int i = 0; i < n; i++){
            /* left side of rectangle with height == heights[i] */
            int start = i; 
            while(!buf.empty() && buf.top().second > heights[i]){
                res = max(res, buf.top().second * (i - buf.top().first));
                start = buf.top().first;
                buf.pop();
            }
            buf.push({start, heights[i]});
        }
        while(!buf.empty()){
            res = max(res, buf.top().second * (n - buf.top().first));
            buf.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> h = {4,2,0,3,2,5};
    cout << h.back() << endl;
    s.largestRectangleArea(h);
    unordered_map<int, bool> values;
    values[1000] = true;
    values[2000] = true;
    auto a = values.begin();
    cout << (a++)->first << endl;
    return 0;
}

// "LRUCache"  "put"  "put"  "get"  "put"  "get"  "put"  "get"  "get"  "get"
//    [2]      [1,1]  [2,2]   [1]   [3,3]   [2]   [4,4]   [1]    [3]    [4]
//   null       null   null    1     null   -1     null    1      3      4
//   null       null   null    1     null   -1     null   -1      3      4
