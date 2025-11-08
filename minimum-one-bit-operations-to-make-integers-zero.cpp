class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans=0;
        int temp=1;
        int k=0;
        while(temp<=n)
        {
            if((temp&n)!=0)
            {
                ans=(1<<(k+1))-ans-1;
            }

            temp=temp<<1;
            k++;
        }

        return ans;
    }
};
