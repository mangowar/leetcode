#include <iostream>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        istringstream path_stream(path);
        string token;
        list<string> buf;
        while(getline(path_stream, token, '/')) {
//            cout << "token = " << token << endl;
            if(token.empty() || token == ".")
                continue;
            else if(token == "..") {
                if (!buf.empty())
                    buf.pop_back();
            }
            else
                buf.push_back(token);
        }
        if(buf.empty())
            return "/";
        for(string s: buf) {
            res += "/" + s;
        }
        return res;
    }
};

int main() {
    string str = "/../";
    string path = "/home/user/Documents/../Pictures";
    string p2 =  "/home//foo/";
    Solution s;
    string res = s.simplifyPath(str);
    cout << res << endl;
    return 0;
}