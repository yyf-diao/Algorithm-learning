class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            // 1. 尾部清理：比当前nums[i]小的全部弹出
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);

            // 2. 清理队头，下标不在窗口 [i?k+1 , i] 就移除
            while(dq.front() <= i - k){
                dq.pop_front();
            }

            // 3. i >= k?1，窗口成型，记录最大值
            if(i >= k - 1){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
