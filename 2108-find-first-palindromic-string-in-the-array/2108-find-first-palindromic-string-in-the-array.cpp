class Solution {
    bool isPalindrome(string &s) {
        int l = 0, r = s.length()-1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
};