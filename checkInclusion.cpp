#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        unordered_map<char, int> fr;
        int k = s1.size();
        for(const auto& c: s1)
        {
            fr[c]++;
        }
        int fr_size = fr.size();
        int l{0}, r{0};
        while(r < s2.size())
        {
            if(fr.find(s2[r]) != fr.end())
            {
                fr[s2[r]]--;
                if(fr[s2[r]] == 0) 
                {
                    fr_size--;
                }
            }
            if(r-l+1 < k)
            {
                r++;
            }
            else if(r-l+1 == k)
            {
                if(fr_size == 0)
                {
                    return true;
                }
                if(fr.find(s2[l]) != fr.end())
                {
                    fr[s2[l]]++;
                    if(fr[s2[l]] == 1)
                    {
                        fr_size++;
                    }
                }
                l++;
                r++;
            }
        }
        return false;
    }
};

int main()
{
    string s1, s2;
    // cin >> s1 >> s2;
    s1 = "adc";
    s2 = "dcda";
    Solution s;
    cout << (s.checkInclusion(s1, s2)? "true": "false") << endl;
    return 0;
}