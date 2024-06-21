#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            frequency[nums[i]]++;
        }
        priority_queue<pair<int, int>> buf;
        for(auto i: frequency)
        {
            buf.push({i.second, i.first});
        }
        for(int i = 0; i < k; i++)
        {
            res.push_back(buf.top().second);
            buf.pop();
        }
        return res;
    }
};
int main()
{
    return 0;
}