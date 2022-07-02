class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int l = 0, r = l + k, count = 0;
        string n = to_string(num);
        while(r <= n.length()) {
            int temp = stoi(string(n.begin() + l, n.begin() + r));
            cout << temp<< " ";
            if (temp == 0) {}
            else if(num%temp == 0) count++;
            r++;
            l++;
        }
        // cout << t << endl;
        return count;
    }
};