class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> seen;
        for (string &s : words) {
            string cur = "";
            for (char &c : s) {
                cur += morse[c - 'a'];
            }
            seen.insert(cur);
        }
        
        return seen.size();
    }
};