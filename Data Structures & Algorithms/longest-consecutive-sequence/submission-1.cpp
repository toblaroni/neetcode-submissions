class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        set<int> distinct_nums(nums.begin(), nums.end());

        int longest_seq = 1;
        int current_seq = 1;

        set<int>::iterator it = distinct_nums.begin();

        for (int i = 0; i < distinct_nums.size()-1; ++i) {
            if (*(it) == *(++it)-1) {
                current_seq++;
            } else {
                // Reset the current sequence
                current_seq = 1;
            }

            if (current_seq > longest_seq)
                longest_seq = current_seq;
        }

        return longest_seq;
    }
};
