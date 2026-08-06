class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()) return res;

        // 按区间左边界排序
        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            auto& last = res.back();
            int curL = intervals[i][0];
            int curR = intervals[i][1];

            if(curL <= last[1]){
                // 重叠，合并，右端选大的
                last[1] = max(last[1], curR);
            }else{
                // 不重叠直接加入
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
