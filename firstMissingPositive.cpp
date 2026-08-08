class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            // nums[i] 在[1,n]范围内，并且没有放到正确位置，就交换
            while(nums[i] >= 1 && nums[i] <= n && nums[nums[i]-1] != nums[i])
            {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        // 找第一个不满足 nums[i]==i+1
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i+1)
            {
                return i+1;
            }
        }
        // 1~n全部齐全
        return n+1;
    }
};
