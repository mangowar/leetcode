#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> borders;
        for(int i = 0; i < s.size(); ++i) {
            borders[s[i]] = i;
        }
        int end = 0;
        int size = 0;
        for(int i = 0; i < s.size(); ++i) {
            size++;
            end = max(end, borders[s[i]]);
            if(i == end) {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};