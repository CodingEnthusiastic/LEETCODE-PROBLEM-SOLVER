class Solution {
public:
    double divide(long long int dividend,long long int divisor) {
        long long res=dividend/divisor;
        if(res >= pow(2,31))
        return pow(2,31)-1;
        if(res<= -pow(2,31))
        {
            return -pow(2,31);
        }
        return res;
    }
};