#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);

        // 第一步：计算左侧乘积
        answer[0] = 1; // 第一个元素左边没有数，乘积=1
        for(int i = 1; i < n; i++){
            answer[i] = answer[i-1] * nums[i-1];
        }

        // 第二步：从右往左，维护右侧乘积right
        int right = 1;
        for(int i = n - 1; i >= 0; i--){
            answer[i] = answer[i] * right;
            right = right * nums[i];
        }
        return answer;
    }
};
