#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_seat = 0;
        int beginning = 0;
        int i = 0;
        while(!seats[i])
        {
            beginning++;
            i++;
        }
        int count = 0;
        for (; i < seats.size(); i++)
        {
            if(!seats[i])
            {
                count++;
            }
            else {
                max_seat = max(max_seat, count - count/2);
                count = 0;
            }
        }
        return max(count, max(max_seat, beginning));
    }
};
int main() {
    Solution s;
    vector<int> a = {0, 1};
    cout << s.maxDistToClosest(a) << endl;
    return 0;
}