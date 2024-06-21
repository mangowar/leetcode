#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return {};
        unordered_map<char, int> t_dict;
        unordered_map<char, int> t_chars;
        int t_count = 0;
        string res = {};
        int l = 0;
        for(const auto i: t) {
            t_dict[i]++;
            t_chars[i] = 0;
        }
        for(int i = 0; i < s.size(); i++) {   
            if(t_dict.find(s[i]) != t_dict.end()) {
                t_chars[s[i]]++;
                if(t_chars[s[i]] <= t_dict[s[i]])
                    t_count++;
            }
            if(t_count == t.size()) {
                while(t_count == t.size()) {
                    if(t_chars.find(s[l]) != t_chars.end()) {
                        t_chars[s[l]]--;
                        if(t_chars[s[l]] < t_dict[s[l]]) {
                            t_count--;
                        }
                    }
                    l++;
                }
                if(res.size() == 0 || res.size() > s.substr(l-1, i-l+2).size())
                    res = s.substr(l-1, i-l+2);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    // string s = "A D O B E C O D E B A N C";
    // string t = "ABC";
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    
    return 0;
}