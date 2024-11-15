class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;

        // Find longest sorted prefix
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        // If already sorted, no need to remove anything
        if (left == n - 1) return 0;

        // Find longest sorted suffix
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }

        // Calculate minimum length by removing middle part entirely
        int minRemove = min(n - left - 1, right);

        // Try merging prefix and suffix with minimal removal
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                minRemove = min(minRemove, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return minRemove;
    }
};
