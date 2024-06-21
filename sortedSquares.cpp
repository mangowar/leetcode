#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int> nums) {
       int l{0}, r =nums.size()-1;
       vector<int> buf;
        while (l <= r) {
            if(nums[l]*nums[l] > nums[r]*nums[r]) {
                buf.push_back(nums[l] * nums[l]);
                l++;
            }
            else {
                buf.push_back(nums[r] * nums[r]);
                r--;
            }
        }
        vector<int> res(buf.rbegin(), buf.rend());
        return res;
    }
};

int main() {
    Solution s;
    s.sortedSquares({1, 2, 3});
    return 0;
}//
// Created by oleg on 07.06.24.
//
