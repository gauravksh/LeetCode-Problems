class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir; 
        string ans = "/";
        string x;
        stringstream ss(path);
        while(getline(ss,x, '/')) {
            if(x == "" || x == ".") continue;
            else if(x == ".." && !dir.empty()) dir.pop();
            else if(x != "..") {
                dir.push(x);
            }
        }
        vector<string> v;
        while(!dir.empty()) {
            v.push_back(dir.top());
            dir.pop();
        }
        reverse(begin(v), end(v));
        for(auto s : v) {
            ans += s;
            ans += '/';
        }
        ans.pop_back();
        
        return ans == "" ? "/" : ans;
    }
};