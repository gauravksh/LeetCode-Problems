class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(char ch : ransomNote) {
            mp[ch]++;
        }
        for(char ch : magazine) {
            if(mp.find(ch) != mp.end()) {
                mp[ch]--;
                if(!mp[ch]) mp.erase(ch);
                if(!mp.size()) return true;
            }
        }
        
        return false;
    }
};