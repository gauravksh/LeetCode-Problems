class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long rev = 0, temp = x;
        int digit = 0;
        while(temp) {
            digit = temp%10;
            rev = rev*10 + digit;
            temp = temp/10;
        }
        if(rev == x) return true;
        else return false;
    }
};