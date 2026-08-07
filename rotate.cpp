class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;   // k大于数组长度，取模，消除无效旋转
        // 1.全部反转
        reverse(nums.begin(), nums.end());
        // 2.反转前k个
        reverse(nums.begin(), nums.begin() + k);
        // 3.反转剩余n?k个
        reverse(nums.begin() + k, nums.end());
    }
};
