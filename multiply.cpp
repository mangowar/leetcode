#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // string res(num1.size()+num2.size(), '0');
        if(num1 == "0" || num2 == "0")
            return "0";
        vector<int> res(num1.size()+num2.size(), 0);
        string buf1(num1.rbegin(), num1.rend());
        string buf2(num2.rbegin(), num2.rend());
        for(int i = 0; i < buf1.size(); i++) {
            for(int j = 0; j < buf2.size(); j++) {
                int d1 = buf1[i] - '0';
                int d2 = buf2[j] - '0';
                res[i+j] += d1*d2;
                res[i+j+1] += res[i+j]/10;
                res[i+j] = res[i+j]%10;
            }
        }
        string res_s;
        vector<int> buf(res.rbegin(), res.rend());
        int start = 0;
        while(start < buf.size() && buf[start] == 0)
        {
            start++;
        }
        for(int i = start; i < buf.size(); ++i) {
            res_s.push_back(buf[i]+'0');
        }
        return res_s;
    }
};

int main() {
    Solution s;
    cout << s.multiply(to_string(__INT64_MAX__), to_string(__INT64_MAX__)) << endl;
    // cout << (short)'a' << ' ' << (short)'b' << endl;
    return 0;
}