#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string result;
        int n = strs.size();
        for(int i = 0; i < n; i++)
        {
            result += (to_string(strs[i].size()) + "#" + strs[i]);
        }
        return result;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> result;
        int size = str.size();
        string buf;
        for(int r = 0; r < size; r++)
        {
            if(str[r] > '0' && str[r] <= '9')
            {
                string num;
                while(r < size && str[r] > '0' && str[r] <= '9')
                {
                    num.push_back(str[r]);
                    r++;
                }
                if(r < size && str[r] == '#')
                {
                    int int_num = stoi(num);
                    r++;
                    for(int i = 0; i < int_num; i++, r++)
                    {
                        buf.push_back(str[r])
                    }
                    result.push_back(buf);
                    buf.clear();
                }
            }
        }
        return result;
    }
};