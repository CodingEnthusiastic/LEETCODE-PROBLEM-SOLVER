class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long int,vector<long long int>>pq;
        for(int i=0;i<gifts.size();i++)
        {
            pq.push(gifts[i]);
        }
        for(int i=0;i<k;i++)
        {
            long long int topper=pq.top();
            pq.pop();
            long long int temp=sqrt(topper);
            pq.push(temp);
        }
        long long int result=0;
        while(pq.empty()==0)
        {
            result+=pq.top();
            pq.pop();
        }
        return result;
    }
};