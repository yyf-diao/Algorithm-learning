class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int lenS = s.size(), lenP = p.size();
        if(lenP > lenS) return res;

        int cntP[26] = {0};
        int cntWin[26] = {0};
        for(char ch : p){
            cntP[ch - 'a']++;
        }
        for(int i = 0; i < lenP; i++){
            cntWin[s[i] - 'a']++;
        }
        if(equal(cntP,cntWin)){
            res.push_back(0);
        }
        for(int right = lenP; right < lenS; right++){
            int leftChar = s[right - lenP] - 'a';
            cntWin[leftChar]--;
            int newChar = s[right] - 'a';
            cntWin[newChar]++;

            if(equal(cntP,cntWin)){
                res.push_back(right - lenP + 1);
            }
        }
        return res;
    }
    bool equal(int a[], int b[]) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};
