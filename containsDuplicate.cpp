#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> founded;
        for(const auto i: nums)
        {
            if(founded.count(i))
                return true;
            else
                founded.insert(i);
        }
        return false;
    }
};