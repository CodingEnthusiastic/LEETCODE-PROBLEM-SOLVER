class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=INT_MIN;
        int start=0;
        int end=height.size()-1;
        while(start<end)
        {
            int z=end-start;
            int v=min(height[start],height[end]);
            int area=z*v;
            if(area>max_area)
            {
                max_area=area;
            }
            if(height[start]<height[end])
                start++;
            else if(height[end]<=height[start])
                end--;
        }
        return max_area;
    }
};