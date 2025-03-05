class Solution {
public:
    long long coloredCells(int n) {
        long long a=(long long)n*(n-1)*2;
        return 1ll+a;
    }
};