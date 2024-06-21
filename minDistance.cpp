#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dist[word1.size()+1][word2.size()+1];
        for(int i = 0; i <= word1.size(); i++) {
            dist[i][0] = i;
        }
        for(int j = 0; j <= word2.size(); j++) {
            dist[0][j] = j;
        }
        for(int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i-1] == word2[j-1]) {
                    dist[i][j] = dist[i-1][j-1];
                }
                else {
                    dist[i][j] = min(dist[i-1][j-1], min(dist[i-1][j], dist[i][j-1])) + 1;
                }
            }
        }
        return dist[n][m];
    }
};

int main() {
    Solution s;
    cout << s.minDistance("a", "b") << endl;
    return 0;
}