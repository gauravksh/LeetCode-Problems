class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> width(n,1);
        stack<int> st;
        st.push(n-1);
        
        for(int i = n-1; i >= 0; i--) {
            while(st.size() > 1 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            width[i] += (st.size() > 1 ? st.top() - i - 1 : st.top() - i);
            st.push(i);
        }
         
        st = stack<int>();
        st.push(0);
        
        for(int i = 0; i < n; i++) {
            while(st.size() > 1 && heights[st.top()] >= heights[i]) st.pop();
            width[i] += (st.size() > 1 ? i - st.top() - 1 : i - st.top());
            st.push(i);
        }
   
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(ans < heights[i] * width[i]) ans = heights[i] * width[i];
        }
        return ans;
    }
};