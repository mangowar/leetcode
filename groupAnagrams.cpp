#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> buffer;
        vector<vector<string>> answ{};
        int n = strs.size();
        int index = 0;
        for(int i = 0; i < n; i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            if(!buffer.count(key))
            {
                answ.push_back({strs[i]});
                buffer[key] = index;
                index++;
            }
            else
            {
                answ[buffer[key]].push_back(strs[i]);
            }
        }
        return answ;
    }
};
int main()
{
    Solution s;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto answ = s.groupAnagrams(strs);
    return 0;
}