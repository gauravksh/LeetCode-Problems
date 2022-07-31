class NumArray {
    vector<int> v;
    int preSum;
public:
    NumArray(vector<int>& nums) {
        this->v = nums;
        this-> preSum = accumulate(begin(v),end(v),0);
    }
    
    void update(int index, int val) {
        preSum -= (v[index] - val);
        v[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = preSum;
        for(int i = 0; i < left; i++) {
            sum -= v[i];
        }
        for(int i = right + 1; i < v.size(); i++) {
            sum -= v[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */