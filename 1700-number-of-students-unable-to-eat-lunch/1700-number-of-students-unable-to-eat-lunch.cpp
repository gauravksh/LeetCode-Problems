class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int i = 0, j = 0, n = students.size();
        for(int i = 0; i < n; i++) {
            if(students[i] != sandwiches[j]) q.push(students[i]);
            else j++;
        }
        int cnt = 0;
        while(!q.empty() && j < n) {
            if(q.front() == sandwiches[j]) {
                q.pop();
                j++;
                cnt = 0;
            }
            else {
                int val = q.front();
                q.pop();
                q.push(val);
                cnt++;
            }
            if(cnt == q.size()) return cnt;
        }
        return 0;
    }
};