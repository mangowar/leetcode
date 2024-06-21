#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        /* string s must include anagrams of p */
        if(s.size() < p.size())
            return {};
        vector<int> res;
        unordered_map<char, int> p_chars;
        for(char c: p){
            p_chars[c]++;
        }
        int l{0};
        int len = p_chars.size();
        for(int i = 0; i < s.size(); i++){
            if(p_chars.count(s[i])){
                p_chars[s[i]]--;
                if(p_chars[s[i]] == 0)
                    len--;
            }
            if(i - l + 1 == p.size()){
                if(len == 0){
                    res.push_back(l);
                }
                if(p_chars.find(s[l]) != p_chars.end()){
                    if(p_chars[s[l]] == 0){
                        len++;
                    }
                    p_chars[s[l]]++;
                }
                l++;
            }
        }
        return res;
    }
};
int main(){
    return 0;
}