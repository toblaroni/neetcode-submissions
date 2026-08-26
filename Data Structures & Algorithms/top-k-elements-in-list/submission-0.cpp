class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // First we count frequency of each element in nums
        unordered_map<int, int> freq_map;
        vector<vector<int>> freq(nums.size()+1);

        for (int n : nums) {
            freq_map[n]++;
        }
        for (auto el : freq_map) {
            freq[el.second].push_back(el.first);
        }

        vector<int> output;
        for (int i = freq.size()-1; i >= 0 && output.size() < k; i--) {
            for (int j : freq[i]) {
                output.push_back(j);

                if (output.size() == k) {
                    return output;
                }
            }
        }

        return output;
    }
};
