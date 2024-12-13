class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<bool>visited(nums.size(),0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        long long int result=0;
        while(pq.empty()==0)
        {
            pair<int,int>temp=pq.top();
            pq.pop();
            if(visited[temp.second]==1)
            {
                continue;
            }
            else
            {
                result+=temp.first;
                visited[temp.second]=1;
            }
            if(temp.second>0)
            {
                visited[temp.second-1]=1;
            }
            if(temp.second<nums.size()-1)
            {
                visited[temp.second+1]=1;
            }

        }

        return result;
    }
};