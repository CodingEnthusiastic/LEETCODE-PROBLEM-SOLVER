class Solution {
public:
    long long minEnd(int n, int x) {
        long long answer=x;
        n--;
        while(n--)
        {
            answer=(answer+1)|x;
        }
        return answer;
    }
};