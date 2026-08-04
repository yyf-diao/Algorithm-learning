class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128];
        for(int i = 0; i < 128; i++) last[i] = -1;

        int maxLen = 0;
        int left = 0;

        for(int right = 0; right < s.size(); right++){
            char c = s[right];
            if(last[c] >= left){
                left = last[c] + 1;
            }
            last[c] = right;

            maxLen = max(maxLen,right - left + 1);
        }
        return maxLen;
    }
};
