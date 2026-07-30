class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> nums_s(nums.begin(), nums.end());
        return nums_s.size() != nums.size()  ;
    }
};