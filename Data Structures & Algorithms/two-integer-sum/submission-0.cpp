class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> output;

        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    output.insert({i, j});
                }
            }
        }

        vector<int> output_v(output.begin(), output.end());
        return output_v;
    }
};
