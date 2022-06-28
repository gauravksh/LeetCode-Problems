class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string i : words) {
            int l = 0, r = i.length() - 1;
            while (l < r) {
                if (i[l]==i[r]) {
                    l++;
                    r--;
                }
                else break;
            }
            if (l >= r) return i;
        }
        return "";
    }
};