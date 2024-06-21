#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[l]) {
                nums[l+1] = nums[i];
                l++;
            }
        }
        
        return l+1;
    }
};

int main() {
    vector<int> v = {1,1,2};
    Solution s;
    s.removeDuplicates(v);
    return 0;
}