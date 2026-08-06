class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int ans = nums[0];
        for(int x : nums){
            pre = max(x, pre + x);
            ans = max(ans, pre);      
        }
        return ans;
    }
};
