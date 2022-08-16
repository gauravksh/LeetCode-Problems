class Solution {
public:
    string smallestNumber(string pattern) {
        string num;
        for(int i = 1; i <= pattern.size()+1; i++) {
            num += i + '0';
        }
        int i;
        while (true) {
            for(i = 0; i < pattern.size(); i++) {
                if(pattern[i] == 'I') {
                    if(num[i] > num[i+1]) {
                        next_permutation(begin(num), end(num));
                        break;
                    }
                }
                else {
                    if(num[i] < num[i+1]) {
                        next_permutation(begin(num), end(num));
                        break;
                    }
                }
            }
            if(i == pattern.size()) return num;
        }
        // string res = num.substr(num.begin(),pattern.size() + 1);
        return num;
    }
};