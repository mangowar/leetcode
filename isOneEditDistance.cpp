#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        if (nt < ns)
            return isOneEditDistance(t, s);
        if (nt > ns + 1)
            return false;
        for (int i = 0; i < ns; i++)
        {
            if(s[i] != t[i])
            {
                if (nt == ns)
                    return s.substr(i + 1) == t.substr(i + 1);
                else
                    return s.substr(i) == t.substr(i+1);
            }
        }
        return true;
    }
};

int main()
{
    string s, t;
    cout << "s: ";
    cin >> s;
    cout << "t: ";
    cin >> t;
    Solution sol;
    cout << ((sol.isOneEditDistance(s, t) == 1) ? "true" : "false") << endl;
    return 0;
}