#include <exception>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> str;
        for (int i = 0, j = 0; i <= chars.size(); i++)
        {
            if(i == chars.size() || chars[i] != chars[j])
            {
                // str += chars[j];
                str.push_back(chars[j]);
                // str += ((i != j+1) ? to_string(i-j): "");
                if(i != j+1)
                {
                    string nums = to_string(i-j);
                    for(auto c: nums)
                        str.push_back(c);
                }
                j = i;
            }
        }
        // cout << str << '\n';
        chars.clear();
        chars = str;
        return chars.size();
    }
};
int main()
{
    Solution s;
    string str = "";
    // cin >> str;
    vector<char> chars(str.begin(), str.end());
    try{
        cout << s.compress(chars) << '\n';
    }
    catch(invalid_argument e){
        cout << "ERRoR!!\n";
        return 0;
    }
    for(auto c: chars)
        cout << c;
    cout << '\n';
    return 0;
}