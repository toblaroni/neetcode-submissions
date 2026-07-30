class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<char> vs(s.begin(), s.end());
        vector<char> vt(t.begin(), t.end());
        sort(vs.begin(), vs.end());
        sort(vt.begin(), vt.end());
        for (int i = 0; i < vs.size(); i++) {
            if (vs[i] != vt[i]) return false;
        }
        return true;
    }
};
