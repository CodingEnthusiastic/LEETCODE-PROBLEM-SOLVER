class Solution {
public:
    int minBitFlips(int start, int goal) {
        int t=0;
        int exor=start^goal;
        while(exor>0)
        {
            t=t+(exor%2==1);
            exor/=2;
        }
        return t;
    }
};