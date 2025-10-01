class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles;
        int div=0;
        int rem=0;
        while(numBottles>=numExchange)
        {
            div=numBottles/numExchange;
            rem=numBottles%numExchange;
            numBottles=div+rem;
            sum=sum+div;
            
        }
        return sum;
    }
};