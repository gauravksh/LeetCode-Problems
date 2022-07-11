class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> cur;
        for(int i = 1; i <= numRows; i++) {
            for(int j = 1; j <= i; j++) {
                if(j == 1 || j == i) cur.push_back(1);
                else cur.push_back(pascal[i-2][j-2] + pascal[i-2][j-1]);
            }
            pascal.push_back(cur);
            cur.clear();
        }
        return pascal;
    }
};