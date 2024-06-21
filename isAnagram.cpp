#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size())
        {
            return false;
        }
        unordered_map<char, int> chars; 
        for(const auto i: s)
        {
            chars[i]++;
        }
        for(const char i: t)
        {
            if(chars.contains(i))
            {
                chars[i]--;
                if(chars[i] == 0)
                    chars.erase(i);
            }
            else
            {
                return false;
            }
        }
        return (chars.empty());
    }
};
int main()
{
    Solution sol;
    string s, t;
    s = "anagram";
    t = "nagaram";
    cout << (sol.isAnagram(s, t)? "true": "false") << endl;
    s = "rat";
    t = "car";
    cout << (sol.isAnagram(s, t)? "true": "false") << endl;
    return 0;
}