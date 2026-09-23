class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums);
        int total_prod = 1;
        int zero_count = 0;

        for (int i : nums) {
            if (i != 0) {
                total_prod *= i;
            } else {
                zero_count++;
            }
        }

        if (zero_count > 1) {
            fill(res.begin(), res.end(), 0);
        } else if (zero_count == 1) {
            int prod = 1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    prod *= nums[i];
                }
            }

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    res[i] = 0;
                } else {
                    res[i] = prod;
                }
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                res[i] = total_prod / nums[i];
            }
        }
        
        return res;
    }
};
