class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //maximum smallest right code
        stack<int>st;
        int n=heights.size();
        vector<int>msr(n,n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&heights[st.top()]>heights[i])
            {
                msr[st.top()]=i;
                st.pop();
            };
            st.push(i);
        };
        while(!st.empty())
        {
            msr[st.top()]=n;
            st.pop();
        };
        
        vector<int>msl(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&heights[st.top()]>heights[i])
            {
                msl[st.top()]=i;
                st.pop();
            };
            st.push(i);
        };
        while(!st.empty())
        {
            msl[st.top()]=-1;
            st.pop();
        };
        //calculation of area
        int area=0;
        for(int i=0;i<n;i++)
        {
            area=max(area,heights[i]*(msr[i]-msl[i]-1));
        };
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans(matrix[0].size(),0);
        int maxa=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    ans[j]++;
                else
                    ans[j]=0;
            }
            maxa=max(maxa,largestRectangleArea(ans));
        };
        return maxa;
    }
};
