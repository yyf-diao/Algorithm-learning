class Solution {
public:
    string minWindow(string s, string t) {
        int need[128] = {0};
        int window[128] = {0};
        int diffKind = 0;
        for(char c : t){
            if(need[c] == 0) diffKind++;
            need[c]++;
        }

        int left = 0;
        int valid = 0;
        int start = 0;
        int minLen = 1e9;

        for(int right = 0; right < s.size(); right++){
            char rChar = s[right];
            if(need[rChar] > 0){
                window[rChar]++;
                if(window[rChar] == need[rChar]){
                    valid++;
                }
            }

            
            while(valid == diffKind){
                int curLen = right - left + 1;
                if(curLen < minLen){
                    minLen = curLen;
                    start = left;
                }

                char lChar = s[left];
                if(need[lChar] > 0){
                    if(window[lChar] == need[lChar]){
                        valid--;
                    }
                    window[lChar]--;
                }
                left++;
            }
        }
        if(minLen == 1e9) return "";
        return s.substr(start, minLen);
    }
};
