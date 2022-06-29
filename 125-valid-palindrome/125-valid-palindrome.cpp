class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        
        while(l < r) {
            
            while (!isalpha(s[l]) && !isdigit(s[l]) && l < r) l++;
            while (!isalpha(s[r]) && !isdigit(s[r]) && l < r) r--;
            if (isupper(s[l])) s[l] = tolower(s[l]);            
            if (isupper(s[r])) s[r] = tolower(s[r]);
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        
        return true;
    }
};