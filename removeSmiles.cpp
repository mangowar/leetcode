#include<iostream>
#include<vector>
using namespace std;

void removeSmiles(string& s) {
    int l = 0, r = 0;
    while(r < s.size())
    {
        if(r+2 < s.size() && s[r] == ':' && s[r+1] == '-' && (s[r+2] == '(' || s[r+2] == ')')) {
            char c = s[r+2];
            r = r+2;
            while(s[r] == c)
            {
                r++;
            }
        }
        else {
            r++;
            l++;
        }
        if(r < s.size()) {
            s[l] = s[r];
        }
    }
    s.resize(l);
}

int main() {
    string s1 = ":-))):-(((((";
    removeSmiles(s1);
    cout << "\"" + s1 + "\"" << endl; 
    return 0;
}