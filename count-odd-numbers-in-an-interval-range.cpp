class Solution {
public:
    int countOdds(int low, int high) {
        int nos=high-low;
        nos=(nos+1)/2;
        if(low%2==1&&high%2==1)
        nos++;
        return nos;
    }
};
