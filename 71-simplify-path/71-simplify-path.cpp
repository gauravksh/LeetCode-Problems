class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir; 
        string ans = "";
        string x;
        stringstream ss(path);
        while(getline(ss,x, '/')) {
            if(x == "" || x == ".") continue;
            else if(x == ".." && !dir.empty()) dir.pop();
            else if(x != "..") {
                dir.push(x);
            }
        }
        while(!dir.empty()) {
            ans = '/' + dir.top() + ans;
            dir.pop();
        }
        if(ans.length() == 0) ans = "/";
        
        return ans;
    }
};