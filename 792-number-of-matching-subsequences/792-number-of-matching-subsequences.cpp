class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        int res = 0;
        for(auto x : words){
            int idx = -1;
            bool flag = false;
            for(char ch : x) {
                flag = false;
                if(mp.find(ch) != mp.end()) {
                    for(int k : mp[ch]) {
                        if(k > idx) {
                            idx = k;
                            flag = true;
                            break;
                        }
                    }
                    if(flag) continue;
                    else break;
                }
                else break;
            }
            if(flag) {
                res++;
                cout << x;
            }
        }
        
        return res;
    }
};