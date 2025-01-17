class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int evens=0;
        for(int i=0;i<derived.size();i++)
        {
            if(derived[i]%2==1)
            evens++;
        }

        return evens%2==0;
    }
};