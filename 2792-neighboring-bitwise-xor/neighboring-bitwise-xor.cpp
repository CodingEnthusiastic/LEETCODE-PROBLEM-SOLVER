class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int exor=0;
        for(int i=0;i<derived.size();i++)
        {
            exor=exor^derived[i];
        }

        return exor==0;
    }
};