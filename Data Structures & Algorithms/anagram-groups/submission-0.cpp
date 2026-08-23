class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (string s : strs) {
            string s_sorted = s;
            sort(s_sorted.begin(), s_sorted.end());
            anagrams[s_sorted].push_back(s);
        }

        vector<vector<string>> output;
        for (auto p : anagrams) {
            output.push_back(p.second);
        }
        return output;
    }
};
