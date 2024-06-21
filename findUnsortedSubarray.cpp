#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start{0}, end{0};
        int max = nums[0];
        int min = nums.back();
        for(int i = 1; i < nums.size(); i++) {
            max = max(nums[i], max);
            if(nums[i] < max) {
                end = i;
            }
        }
        for(int i = nums.size()-2; i >= 0; i--) {
            min = min(min, nums[i]);
            if(nums[i] > min) {
                start = i;
            }
        }
        return end - start - 1;
    }
};
int main() {
    Solution s;
    vector<int> v = {1,2,3,3,3};
    s.findUnsortedSubarray(v);
}
