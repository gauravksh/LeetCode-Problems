class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();
        int l , r = 0;
        if (m < n) return -1;
        
        while(r < m) {
            l = 0;
            while(haystack[r] != needle[l] && r < m) r++;
            int tmp = r;
            while(l < n){
                if(needle[l]==haystack[r]) {
                    l++;
                    r++;
                }
                else break;
            }
            
            if(l == n) return tmp;
            r = ++tmp;
        }
        return -1;
    }
};