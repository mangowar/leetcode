using namespace std;
class Solution {
public:
    Solution() {
        int n = 0;
        for(int i = 0; i < 7; i++){ 
            for(int j = 0; j < 7; j++) {
                matrix[i][j] = n % 10;
                n++;
            }
        }
    }
    int rand10() {
        while(1) {
            int r = rand7()-1;
            int c = rand7()-1;
            if((r == 6) or (r == 5 and c >=5))
                continue;
            return matrix[r][c]+1;
        }
    }
private:
    int matrix[7][7];
};