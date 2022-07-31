class NumArray {
private:
    vector<int> nums;
    int n;
    vector<int> seg;
    
    // build segment tree in (nlogn)
    int build(int start, int end, int node) {
        if(start == end)
            return seg[node] = nums[start];
        
        int mid = start + (end - start)/2;
        int leftsum = build(start, mid, 2 * node + 1);
        int rightsum = build(mid+1, end, 2 * node + 2);
        return seg[node] = leftsum + rightsum;
    }
    
    // finding sum in range in (logn)
    int sumRange(int left, int right, int segleft, int segright, int node) {
        if((left > segright) or (right < segleft)) return 0;
        if((segleft >= left) and (segright <= right)) return seg[node];
        
        int mid = segleft + (segright - segleft) / 2;
        int leftsum = sumRange(left, right, segleft, mid, 2*node+1);
        int rightsum = sumRange(left, right, mid+1, segright, 2*node+2);
        return leftsum + rightsum;
    }

    // updating value in segment tree (logn)
    int update(int index, int val, int segleft, int segright, int node) {
        if((index < segleft) or (index > segright)) return seg[node];
        if(segleft == segright) return seg[node] = val;
        
        int mid = segleft + (segright - segleft) / 2;
        int leftsum = update(index, val, segleft, mid, 2*node+1);
        int rightsum = update(index, val, mid+1, segright, 2*node+2);
        return seg[node] = leftsum+rightsum;
    }
    
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        seg.resize(n*4);
        build(0, n-1, 0);
    }
    
    void update(int index, int val) {
        update(index, val, 0, n-1, 0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(left, right, 0, n-1, 0);
    }
};
