class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector<string>> mp;
        for (const string& path : paths) {
            string pathStart;
            int i = 0;
            while (path[i] != ' ') {
                pathStart.push_back(path[i]);
                i++;
            }
            i++;
            
            while (i < path.size()) {
                string fileName, fileData;
                while (path[i] != '(') {
                    fileName.push_back(path[i]);
                    i++;
                }
                i++;
                while (path[i] != ')') {
                    fileData.push_back(path[i]);
                    i++;
                }
                i += 2;
                mp[fileData].push_back(pathStart + "/" + fileName);
            }     
        }
        
        vector<vector<string>> res;
        for (const auto& [key, value] : mp)
            if (value.size() > 1)
                res.push_back(value);
        
        return res;
    }
};