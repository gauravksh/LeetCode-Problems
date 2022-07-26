class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for(auto x : address) {
            if(x == '.')
                res += "[.]";
            else res += x;
        }
        return res;
    }
};