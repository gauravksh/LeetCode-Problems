class Solution {
public:
    int compareVersion(string v1, string v2) {
        string left, right;
        int i = 0, j = 0, m = v1.size(), n = v2.size(), l, r;
        
        while(i < m || j < n) {
            while(i < m && v1[i] != '.') left += v1[i++];
            i++;
            while(j < n && v2[j] != '.') right += v2[j++];
            j++;
            if(left.size()) l = stoi(left);
            else l = 0;
            if(right.size()) r = stoi(right);
            else r = 0;
            if(l < r) return -1;
            if(l > r) return 1;
            left = "";
            right = "";
        }
        
        return 0;
    }
};