class Solution {
public:
    
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Sort the nums array to make it easier to count pairs within the bounds
        sort(nums.begin(), nums.end());
        long long counter = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            int left = i + 1;
            int low_bound = lower - nums[i];
            int high_bound = upper - nums[i];
            int low = lower_bound(nums.begin() + left, nums.end(), low_bound) - nums.begin();
            int high = upper_bound(nums.begin() + left, nums.end(), high_bound) - nums.begin() - 1;

            if (low <= high) {
                counter += high - low + 1;
            }
        }
        return counter;
    }
    
};