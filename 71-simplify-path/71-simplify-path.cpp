class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir; 
        string ans = "";
        int i = 0;
        while(i < path.size()) {
            if(path[i] == '/') i++;
            else if(path[i] == '.') {
                int cur = i;
                int len = 0;
                while(path[i] != '/' && i < path.size()) {
                    if(path[i] == '.') len++;
                    else len = 0;
                    i++;
                }
                if(len > 2 || len == 0) dir.push(path.substr(cur,i - cur));
                else if(len == 2 && !dir.empty()) dir.pop();
            }
            else {
                int cur = i;
                while(path[i] != '/' && i < path.size()) i++;
                dir.push(path.substr(cur,i - cur));
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