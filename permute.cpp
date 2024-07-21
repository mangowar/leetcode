#include<queue>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> r;
        do {
            r.insert(nums);
        }
        while(next_permutation(nums.begin(), nums.end()));
        r.insert(nums);
        vector<vector<int>> res(r.begin(), r.end());
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, -1, 1};
    vector<int> nums1 = {-2, -1, 3};
    cout << s.permute(nums1).size() << endl;
    return 0;
}