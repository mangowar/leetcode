#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "0" && b == "0")
            return "0";
        if(a.size() < b.size())
            return addBinary(b, a);
        vector<short> r_a; 
        vector<short> r_b;
        string res;
        for(char c: a)
            r_a.push_back((short)(c - '0')); 
        for(char c: b)
            r_b.push_back((short)(c -'0')); 
        reverse(r_a.begin(), r_a.end());
        reverse(r_b.begin(), r_b.end());
        r_a.push_back(0);
        for(int i = 0; i < r_a.size()-1; i++) {
            if(i < r_b.size()) {
                short buf = r_a[i] + r_b[i];
                res.push_back('0' + buf%2);
                r_a[i+1] += buf/2;
            }
            else {
                res.push_back('0' + r_a[i]%2);
                r_a[i+1] += r_a[i]/2;
            }
        }
        if(r_a.back())
            res.push_back('0' + r_a.back());
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("1010", "1011") << endl;
    return 0;
}