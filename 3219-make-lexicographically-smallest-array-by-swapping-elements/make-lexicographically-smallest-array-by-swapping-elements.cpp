class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> suffix;
        int n = nums.size();

        for (int i = 0; i < n; ++i) 
        {
            suffix.push_back({nums[i], i});
        }

        sort(suffix.begin(), suffix.end());

        vector<vector<pair<int, int>>>groupedSuffix;
        groupedSuffix.push_back({suffix[0]});

        for(int i = 1; i < n; ++i) 
        {
            if (suffix[i].first - suffix[i - 1].first <= limit) 
            {
                groupedSuffix.back().push_back(suffix[i]);
            } 
            else 
            {
                groupedSuffix.push_back({suffix[i]});
            }
        }

        for (const auto& group : groupedSuffix) 
        {
            vector<int> indices;
            for (const auto& [value, index] : group) 
            {
                indices.push_back(index);
            }

            sort(indices.begin(), indices.end());

            for (size_t i = 0; i < indices.size(); ++i) {
                nums[indices[i]] = group[i].first;
            }
        }

        return nums;
    }
};
