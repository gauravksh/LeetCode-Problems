class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> res;
        int n = image.size();
        for (int i = 0; i < n; i++) {
            int l = 0, r = n-1;
            while (l < r) {
                swap(image[i][l], image[i][r]);
                image[i][l] = 1 - image[i][l];
                image[i][r] = 1 - image[i][r];
                l++;
                r--;
            }
            if (n&1) image[i][l] = 1 - image[i][l];
        }
        return image;
    }
};