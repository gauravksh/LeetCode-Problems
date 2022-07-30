class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cur = 0;
        for(auto x : logs) {
            if(x == "../" && cur > 0) cur--;
            else if(x != "./" && x != "../") cur++;
        }
        return cur;
    }
};