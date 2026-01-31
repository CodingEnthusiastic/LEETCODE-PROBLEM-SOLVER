class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start=0;
        int end=letters.size()-1;
        int mid=0;
        char c=letters[0];
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(letters[mid]+'0'>target+'0')
            {
                c=letters[mid];
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return c;
        
    }
};
