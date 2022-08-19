class Solution {
    static bool comp(string &a, string& b) {
        if(a.size() == b.size()) return a < b;
        return a.size() > b.size();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), comp);
        int i,j,n = s.length(), m;
        for(auto x : dictionary) {
            i = 0;
            j = 0;
            m = x.size();
            while(i < n && j < m) {
                if(s[i] == x[j]) {
                    i++;
                    j++;
                }
                else i++;
            }
            if(j == m) return x;
        }
        
        return "";
    }
};